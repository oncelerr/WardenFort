#include "WardenFort.h"
#include "ui_wardenfort.h"
#include <QColor>
#include <QTableWidgetItem>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <QApplication>
#include <QThread>
#include <iphlpapi.h>
#include <ctime>
#include <QScrollBar>
#include <pcap.h>
#include <tchar.h>
#include <QDebug>
#include "accountsettings.h"
#include "passwordsec.h"
#include "login.h"
#include "loginsession.h"
#include <QFileDialog>

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QUrlQuery>
#include <QMessageBox>

#pragma comment(lib, "Ws2_32.lib")

int i = 0;
int j = 0;
int k = 0;
int portScanningDetected = 0;
int DOSDetected = 0;
int lastFoundRow = -1;

bool stopRequested = false;

WardenFort::WardenFort(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::WardenFort)
{
    ui->setupUi(this);

    connect(ui->tableWidget, &QTableWidget::itemClicked, this, &WardenFort::onRowClicked);

    networkManager = new QNetworkAccessManager(this);
    manager = new QNetworkAccessManager(this);

    // Set initial width of listWidget to 201 and hide triReversedButton
    ui->listWidget->setFixedWidth(201);
    ui->triReversedButton->setVisible(false);

    // Connect the clicked() signals of the buttons to their respective slots
    connect(ui->triButton, &QPushButton::clicked, this, &WardenFort::onTriButtonClicked);
    connect(ui->triReversedButton, &QPushButton::clicked, this, &WardenFort::onTriReversedButtonClicked);
    connect(ui->profilePushButton, &QPushButton::clicked, this, &WardenFort::onProfilePushButtonClicked);
    connect(ui->profileLessButton, &QPushButton::clicked, this, &WardenFort::onProfileLessButtonClicked);
    connect(ui->searchBTN, &QPushButton::clicked, this, &WardenFort::performSearch);
    connect(ui->actionSave, &QAction::triggered, this, &WardenFort::saveDataToFile);
    connect(ui->actionStart, &QAction::triggered, this, &WardenFort::scanActiveLANAdapters);
    connect(ui->actionCheck_Online, &QAction::triggered, this, &WardenFort::readCSV);
    connect(ui->actionStop, &QAction::triggered, this, &WardenFort::stopScanningActiveLANAdapters);
    connect(ui->actionRestart, &QAction::triggered, this, &WardenFort::restartScanningActiveLANAdapters);

    hideSpecifiedButtons();

    ui->tableWidget->setColumnWidth(0, 120);
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(2, 100);
    ui->tableWidget->setColumnWidth(3, 50);
    ui->tableWidget->setColumnWidth(4, 50);
    ui->tableWidget->setColumnWidth(6, 30);
    ui->tableWidget->setColumnWidth(7, 30);
    ui->tableWidget->setColumnWidth(8, 250);

    loginsession* log = new loginsession;
    QString Name = log->username;

    ui->welcome_text->setText(Name);
}

WardenFort::~WardenFort()
{
    delete ui;
}


void WardenFort::settrafficAnomalies(const QString& text) {
    ui->trafficAnomalies->setText(text);
}

void WardenFort::setcriticalAnomalies(const QString& text) {
    ui->criticalDetections->setText(text);
}

void WardenFort::setOverallAlert(const QString& text) {
    ui->overallAlert->setText(text);
}

QTableWidget* WardenFort::getTableWidget() {
    return ui->tableWidget;

}

void WardenFort::setWelcomeText(const QString& text) {
    ui->welcome_text->setText(text);
}

// Define TCP header flags
#define TH_FIN  0x01
#define TH_SYN  0x02
#define TH_RST  0x04
#define TH_PUSH 0x08
#define TH_ACK  0x10
#define TH_URG  0x20

constexpr int MAX_EXPECTED_PAYLOAD_LENGTH = 9999; // Maximum expected payload length
constexpr int MIN_EXPECTED_PAYLOAD_LENGTH = 0;    // Minimum expected payload length (can be adjusted as needed)
constexpr int MAX_EXPECTED_PACKET_LENGTH = 1514; // Maximum expected packet length
constexpr int MAX_PACKET_LENGTH_THRESHOLD = 9999; // Threshold for detecting unusually large packets
constexpr int MAX_DOS_DETECTED_THRESHOLD = 10;    // Threshold for DoS attack detection
constexpr int MAX_NORMAL_TRANSFER_SIZE = 9999;      // Threshold for data exfiltration

typedef struct ip_address {
    u_char byte1;
    u_char byte2;
    u_char byte3;
    u_char byte4;
} ip_address;

typedef struct ip_header {
    u_char  ver_ihl; // Version (4 bits) + IP header length (4 bits)
    u_char  tos;     // Type of service
    u_short tlen;    // Total length
    u_short identification; // Identification
    u_short flags_fo; // Flags (3 bits) + Fragment offset (13 bits)
    u_char  ttl;      // Time to live
    u_char  proto;    // Protocol
    u_short crc;      // Header checksum
    ip_address  saddr; // Source address
    ip_address  daddr; // Destination address
    u_int  op_pad;     // Option + Padding
} ip_header;

QString getProtocolName(u_char protocol) {
    switch (protocol) {
    case IPPROTO_ICMP:
        return "ICMP";
    case IPPROTO_TCP:
        return "TCP";
    case IPPROTO_UDP:
        return "UDP";
    case IPPROTO_IPV6:
        return "IPv6";
    case IPPROTO_ESP:
        return "ESP";
    case IPPROTO_AH:
        return "AH";
    case IPPROTO_ICMPV6:
        return "ICMPv6";
    case IPPROTO_PIM:
        return "PIM";
    case IPPROTO_L2TP:
        return "L2TP";
    case IPPROTO_SCTP:
        return "SCTP";
    case IPPROTO_RAW:
        return "RAW";
    // Add more protocols as needed
    default:
        return "Unknown";
    }
}

typedef struct udp_header {
    u_short sport; // Source port
    u_short dport; // Destination port
    u_short len;   // Datagram length
    u_short crc;   // Checksum
} udp_header;

struct ICMPHeader {
    uint8_t type;      // ICMP message type
    uint8_t code;      // ICMP message code
    uint16_t checksum; // ICMP message checksum
                       // Additional fields if needed
};

struct my_tcphdr {
    u_short th_sport;   // source port
    u_short th_dport;   // destination port
    u_int th_seq;       // sequence number
    u_int th_ack;       // acknowledgement number
    u_char th_offx2;    // data offset, rsvd
    u_char th_flags;
    u_short th_win;     // window
    u_short th_sum;     // checksum
    u_short th_urp;     // urgent pointer
};

bool isFilteredAdapter(pcap_if_t* adapter) {
    // Check if adapter is a WAN miniport or VirtualBox adapter by description
    if (adapter->description) {
        QString description = QString(adapter->description).toLower();
        if (description.contains("wan miniport") || description.contains("virtualbox"))
            return true;
    }

    // Check if adapter is a loopback adapter (npf_loopback)
    if (adapter->flags & PCAP_IF_LOOPBACK)
    {
        return true;
    }

    // Check if adapter is inactive
    if (!(adapter->flags & PCAP_IF_CONNECTION_STATUS_CONNECTED))
        {
        return true;
    }

    return false;
}

BOOL WardenFort::LoadNpcapDlls()
{
    _TCHAR npcap_dir[512];
    UINT len;
    len = GetSystemDirectory(npcap_dir, 480);
    if (!len) {
        qDebug() << "Error in GetSystemDirectory:" << GetLastError();
        return FALSE;
    }
    _tcscat_s(npcap_dir, 512, _T("\\Npcap"));
    if (SetDllDirectory(npcap_dir) == 0) {
        qDebug() << "Error in SetDllDirectory:" << GetLastError();
        return FALSE;
    }
    return TRUE;
}

bool WardenFort::isFilteredAdapter(pcap_if_t* adapter)
{
    if (adapter->description) {
        QString description = QString(adapter->description).toLower();
        if (description.contains("wan miniport") || description.contains("virtualbox"))
            return true;
    }

    if (adapter->flags & PCAP_IF_LOOPBACK)
    {
        return true;
    }

    if (!(adapter->flags & PCAP_IF_CONNECTION_STATUS_CONNECTED))
    {
        return true;
    }

    return false;
}

void packetHandler(WardenFort* wardenFort, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    bool isVeryBottom = false;

    struct tm ltime;
    char timestr[16];
    ip_header *ih;
    udp_header *uh;
    u_int ip_len;
    u_short sport, dport;
    time_t local_tv_sec;

    local_tv_sec = pkthdr->ts.tv_sec;
    localtime_s(&ltime, &local_tv_sec);
    strftime(timestr, sizeof timestr, "%H:%M:%S", &ltime);

    ih = (ip_header *)(packet + 14); // length of ethernet header

    ip_len = (ih->ver_ihl & 0xf) * 4;
    uh = (udp_header *)((u_char*)ih + ip_len);

    sport = ntohs(uh->sport);
    dport = ntohs(uh->dport);

    struct tm* timeinfo;
    char buffer[80];
    time_t packet_time = static_cast<time_t>(pkthdr->ts.tv_sec);
    packet_time += 28800;
    timeinfo = gmtime(&packet_time);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    QString timestamp = QString(buffer);

    QString packetInfo = "Timestamp: " + timestamp + "\n";
    packetInfo += "Packet length: " + QString::number(pkthdr->len) + " bytes\n";
    packetInfo += "Captured length: " + QString::number(pkthdr->caplen) + " bytes\n";

    const ip_header* ipHeader = reinterpret_cast<const ip_header*>(packet);
    const struct my_tcphdr* tcpHeader = reinterpret_cast<const struct my_tcphdr*>(packet + sizeof(ip_header));

    QString sourceIp = QString("%1.%2.%3.%4")
                           .arg(ih->saddr.byte1)
                           .arg(ih->saddr.byte2)
                           .arg(ih->saddr.byte3)
                           .arg(ih->saddr.byte4);
    QString destIp = QString("%1.%2.%3.%4")
                         .arg(ih->daddr.byte1)
                         .arg(ih->daddr.byte2)
                         .arg(ih->daddr.byte3)
                         .arg(ih->daddr.byte4);

    QString sourcePort = QString::number(ntohs(sport));
    QString destPort = QString::number(ntohs(tcpHeader->th_dport));
    QString flags;
    if (tcpHeader->th_flags & TH_SYN) flags += "SYN ";
    if (tcpHeader->th_flags & TH_ACK) flags += "ACK ";
    if (tcpHeader->th_flags & TH_FIN) flags += "FIN ";

    int tcpHeaderLength = (tcpHeader->th_offx2 >> 4) * 4;

    int payloadLength = pkthdr->caplen - sizeof(ip_header) - tcpHeaderLength;

    QString info = QString("No Information");

    QString protocol = getProtocolName(ih->proto);

    if (ipHeader->proto == IPPROTO_ICMP) {
        int totalLength = ntohs(ipHeader->tlen);
        int icmpHeaderLength = sizeof(ICMPHeader);
        int icmpPayloadLength = totalLength - sizeof(ip_header) - icmpHeaderLength;
        constexpr int MAX_ICMP_PAYLOAD_LENGTH = 10;
        if (icmpPayloadLength > MAX_ICMP_PAYLOAD_LENGTH) {
            info = QString("Large ICMP Echo Request detected. Payload Length: %1").arg(icmpPayloadLength);
        }
    }

    if (tcpHeader->th_flags & TH_SYN && !(tcpHeader->th_flags & TH_ACK)) {
        if (ntohs(tcpHeader->th_dport) >= 1 && ntohs(tcpHeader->th_dport) <= 1024) {
            info = QString("Port Scanning Detected. Source: %1 Destination Port: %2").arg(sourceIp).arg(destPort);
        }
    }

    if (pkthdr->caplen >= MAX_EXPECTED_PACKET_LENGTH) {
        info = QString("Possible Denial of Service (DoS) Attack Detected.").arg(pkthdr->caplen);
    }else if (pkthdr->caplen >= MAX_PACKET_LENGTH_THRESHOLD) {
        info = QString("Unusually large packet detected. Packet Length: %1").arg(pkthdr->caplen);
    }

    if (DOSDetected > MAX_DOS_DETECTED_THRESHOLD) {
        info = QString("DoS attack threshold exceeded. Total DoS attacks detected: %1").arg(DOSDetected);
    }

    if (payloadLength > MIN_EXPECTED_PAYLOAD_LENGTH && payloadLength < MAX_EXPECTED_PAYLOAD_LENGTH) {
        u_short destPort = ntohs(tcpHeader->th_dport);
        switch (destPort) {
        case 6667:
            info = QString("Malware communication detected (IRC-based malware). Destination port: %1").arg(destPort);
            break;
        default:
            const char* payload = reinterpret_cast<const char*>(tcpHeader) + sizeof(struct my_tcphdr);
            if (strstr(payload, "malicious_pattern")) {
                info = QString("Malware communication detected (suspicious payload content). Destination port: %1").arg(destPort);
            }
            break;
        }
    }

    if (payloadLength > MIN_EXPECTED_PAYLOAD_LENGTH && payloadLength < MAX_EXPECTED_PAYLOAD_LENGTH) {
        const char* payload = reinterpret_cast<const char*>(tcpHeader) + sizeof(struct my_tcphdr);
        if (strstr(payload, "confidential_data_pattern")) {
            info = QString("Data exfiltration detected. Suspicious pattern found in payload.");
        }
        else if (payloadLength > MAX_NORMAL_TRANSFER_SIZE) {
            info = QString("Data exfiltration detected. Unusually large payload size.");
        }
    }

    if (tcpHeader->th_flags & TH_SYN && !(tcpHeader->th_flags & TH_ACK)) {
        if (ntohs(tcpHeader->th_dport) >= 1 && ntohs(tcpHeader->th_dport) <= 1024) {
            info = QString("Network Reconnaissance Detected. Source: %1 Destination Port:%2").arg(sourceIp).arg(destPort);
        }
    }

    if (tcpHeader->th_flags & (TH_FIN | TH_SYN | TH_RST | TH_PUSH | TH_ACK | TH_URG)) {
        int flagCount = 0;
        flagCount += tcpHeader->th_flags & TH_FIN ? 1 : 0;
        flagCount += tcpHeader->th_flags & TH_SYN ? 1 : 0;
        flagCount += tcpHeader->th_flags & TH_RST ? 1 : 0;
        flagCount += tcpHeader->th_flags & TH_PUSH ? 1 : 0;
        flagCount += tcpHeader->th_flags & TH_ACK ? 1 : 0;
        flagCount += tcpHeader->th_flags & TH_URG ? 1 : 0;

        if (flagCount != 1 && !(tcpHeader->th_flags & (TH_SYN | TH_ACK)) && !(tcpHeader->th_flags & (TH_FIN | TH_ACK))) {
            // Protocol anomaly detected
            info = QString("Protocol Anomaly Detected.").arg(sourceIp).arg(destIp);
        }
    }

    if (protocol == "TCP" || protocol == "UDP"){
        static QString lastSourceIp; // Variable to store the last source IP address
        static int consecutiveCount = 0; // Variable to count consecutive occurrences

        QTableWidget* tableWidget = wardenFort->getTableWidget();
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(timestamp));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString(sourceIp)));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString(destIp)));
        tableWidget->setItem(row, 3, new QTableWidgetItem(sourcePort));
        tableWidget->setItem(row, 4, new QTableWidgetItem(destPort));
        tableWidget->setItem(row, 5, new QTableWidgetItem(flags));
        tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(pkthdr->caplen)));
        tableWidget->setItem(row, 7, new QTableWidgetItem(protocol));
        tableWidget->setItem(row, 8, new QTableWidgetItem(info));

        if (payloadLength > MAX_EXPECTED_PAYLOAD_LENGTH) {
            //wardenFort->settrafficAnomalies(QString::number(i));
            //k = i + j;
            //wardenFort->setOverallAlert(QString::number(k));
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                //tableWidget->item(row, col)->setBackground(QColor(73, 75, 44));
            }
        }

        if (tcpHeader->th_flags & TH_SYN && !(tcpHeader->th_flags & TH_ACK)) {
            //wardenFort->settrafficAnomalies(QString::number(i));
            //k = i + j;
            //wardenFort->setOverallAlert(QString::number(k));
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                //tableWidget->item(row, col)->setBackground(QColor(67, 75, 44));
            }
        }

        if (payloadLength < MIN_EXPECTED_PAYLOAD_LENGTH) {
            //wardenFort->settrafficAnomalies(QString::number(i));
            //k = i + j;
           // wardenFort->setOverallAlert(QString::number(k));
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                //->item(row, col)->setBackground(QColor(62, 75, 44)); // Change row color to red
            }
        }

        if (ipHeader->proto == IPPROTO_ICMP) {
            int totalLength = ntohs(ipHeader->tlen);
            int icmpHeaderLength = sizeof(ICMPHeader);
            int icmpPayloadLength = totalLength - sizeof(ip_header) - icmpHeaderLength;
            constexpr int MAX_ICMP_PAYLOAD_LENGTH = 10;
            if (icmpPayloadLength > MAX_ICMP_PAYLOAD_LENGTH) {
                //wardenFort->settrafficAnomalies(QString::number(i));
                //k = i + j;
               //wardenFort->setOverallAlert(QString::number(k));
                for (int col = 0; col < tableWidget->columnCount(); ++col) {
                    //tableWidget->item(row, col)->setBackground(QColor(44, 75, 68));
                }
            }
        }

        // Port scanning detector
        if (tcpHeader->th_flags & TH_SYN && !(tcpHeader->th_flags & TH_ACK)) {
            // Check if the destination port is in a range commonly used for scanning
            if (ntohs(tcpHeader->th_dport) >= 1 && ntohs(tcpHeader->th_dport) <= 1024) {
                // Port scanning detected
                //TEST qDebug() << "Port Scanning Detected. Source:" << sourceIp << " Destination Port:" << destPort;
               // k = i + j;
                //wardenFort->setOverallAlert(QString::number(k));

                for (int col = 0; col < tableWidget->columnCount(); ++col) {
                    //tableWidget->item(row, col)->setBackground(QColor(61, 44, 75));
                }
            }
        }

        if (pkthdr->caplen >= MAX_EXPECTED_PACKET_LENGTH) {
            // DoS attack suspected due to excessively large packet size
            //TEST qDebug() << "Possible Denial of Service (DoS) Attack Detected. Packet Length:" << pkthdr->caplen;

            // Increment counters
            j++;
            wardenFort->settrafficAnomalies(QString::number(j));
            k = i + j;
            wardenFort->setOverallAlert(QString::number(k));

            // Log the event or take appropriate action

            // Change row color to denote potential DoS attack
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                tableWidget->item(row, col)->setBackground(QColor(163, 0, 0));
            }
        }

        // Check if the packet length exceeds the threshold for unusually large packets
        else if (pkthdr->caplen >= MAX_PACKET_LENGTH_THRESHOLD) {
            // Log the event or take appropriate action
            //TEST qDebug() << "Unusually large packet detected. Packet Length:" << pkthdr->caplen;
            //i++;
            //wardenFort->settrafficAnomalies(QString::number(i));
           // k = i + j;
            //wardenFort->setOverallAlert(QString::number(k));
            // Add code here to handle the event, such as logging or alerting

            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                //tableWidget->item(row, col)->setBackground(QColor(75, 44, 62)); // Change row color to red
            }
        }

        if (payloadLength > MIN_EXPECTED_PAYLOAD_LENGTH && payloadLength < MAX_EXPECTED_PAYLOAD_LENGTH) {
            // Analyze destination port for known malware communication ports
            u_short destPort = ntohs(tcpHeader->th_dport);
            switch (destPort) {
            case 6667: // Example port used by IRC-based malware
                //TEST qDebug() << "Malware communication detected (IRC-based malware). Destination port:" << destPort;
                //k = i + j;
                //wardenFort->setOverallAlert(QString::number(k));
                for (int col = 0; col < tableWidget->columnCount(); ++col) {
                    //tableWidget->item(row, col)->setBackground(QColor(75, 44, 44)); // Change row color to red
                }
                break;
                // Add more cases for other known malware communication ports as needed
            default:
                // Check for suspicious payload content
                const char* payload = reinterpret_cast<const char*>(tcpHeader) + sizeof(struct my_tcphdr);
                if (strstr(payload, "malicious_pattern")) {
                    //TEST qDebug() << "Malware communication detected (suspicious payload content). Destination port:" << destPort;
                    //k = i + j;
                    //wardenFort->setOverallAlert(QString::number(k));
                    for (int col = 0; col < tableWidget->columnCount(); ++col) {
                        //tableWidget->item(row, col)->setBackground(QColor(75, 44, 44)); // Change row color to red
                    }
                }
                break;
            }
        }

        if (payloadLength > MIN_EXPECTED_PAYLOAD_LENGTH && payloadLength < MAX_EXPECTED_PAYLOAD_LENGTH) {
            // Analyze payload content for suspicious data transfer patterns
            const char* payload = reinterpret_cast<const char*>(tcpHeader) + sizeof(struct my_tcphdr);
            // Example: Check for presence of sensitive keywords or patterns
            if (strstr(payload, "confidential_data_pattern")) {
                //TEST qDebug() << "Data exfiltration detected. Suspicious pattern found in payload.";
                i++;
                wardenFort->settrafficAnomalies(QString::number(i));
                k = i + j;
                wardenFort->setOverallAlert(QString::number(k));
                for (int col = 0; col < tableWidget->columnCount(); ++col) {
                    tableWidget->item(row, col)->setBackground(QColor(163, 0, 0)); // Change row color to red
                }
            }
            // Example: Check for unusually high data transfer volume
            else if (payloadLength > MAX_NORMAL_TRANSFER_SIZE) {
                //TEST qDebug() << "Data exfiltration detected. Unusually large payload size.";
                i++;
                wardenFort->settrafficAnomalies(QString::number(i));
                k = i + j;
                wardenFort->setOverallAlert(QString::number(k));
                for (int col = 0; col < tableWidget->columnCount(); ++col) {
                    tableWidget->item(row, col)->setBackground(QColor(163, 0, 0)); // Change row color to red
                }
            }
            // Add more detection criteria as needed based on your network and security policies
        }

        if (tcpHeader->th_flags & TH_SYN && !(tcpHeader->th_flags & TH_ACK)) {
            // Check if the destination port is commonly used for scanning
            if (ntohs(tcpHeader->th_dport) >= 1 && ntohs(tcpHeader->th_dport) <= 1024) {
                // Network reconnaissance detected
                //TEST qDebug() << "Network Reconnaissance Detected. Source:" << sourceIp << " Destination Port:" << destPort;
                //i++;
                //wardenFort->settrafficAnomalies(QString::number(i));
                //k = i + j;
                //wardenFort->setOverallAlert(QString::number(k));
                for (int col = 0; col < tableWidget->columnCount(); ++col) {
                    //tableWidget->item(row, col)->setBackground(QColor(75, 44, 44)); // Change row color to red
                }
            }
        }

        if (tcpHeader->th_flags & (TH_FIN | TH_SYN | TH_RST | TH_PUSH | TH_ACK | TH_URG)) {
            // Flags should not have multiple bits set, except for SYN-ACK or FIN-ACK
            int flagCount = 0;
            flagCount += tcpHeader->th_flags & TH_FIN ? 1 : 0;
            flagCount += tcpHeader->th_flags & TH_SYN ? 1 : 0;
            flagCount += tcpHeader->th_flags & TH_RST ? 1 : 0;
            flagCount += tcpHeader->th_flags & TH_PUSH ? 1 : 0;
            flagCount += tcpHeader->th_flags & TH_ACK ? 1 : 0;
            flagCount += tcpHeader->th_flags & TH_URG ? 1 : 0;

            if (flagCount != 1 && !(tcpHeader->th_flags & (TH_SYN | TH_ACK)) && !(tcpHeader->th_flags & (TH_FIN | TH_ACK))) {
                // Protocol anomaly detected
                //TEST qDebug() << "Protocol Anomaly Detected. Source:" << sourceIp << " Destination:" << destIp;
                //i++;
                //wardenFort->settrafficAnomalies(QString::number(i));
               // k = i + j;
                //wardenFort->setOverallAlert(QString::number(k));
                for (int col = 0; col < tableWidget->columnCount(); ++col) {
                    //tableWidget->item(row, col)->setBackground(QColor(75, 44, 44)); // Change row color to red
                }
            }
        }

        // Print overall packet information
        //TEST qDebug().noquote() << packetInfo << "Source IP:" << sourceIp << "Destination IP:" << destIp << "Source Port:" << sourcePort << "Destination Port:" << destPort << "Flags:" << flags << "Captured length:" << pkthdr->caplen;
        //TEST qDebug() << portScanningDetected << DOSDetected;
        // Analyze the TCP packet
        //analyzeTCPPacket(packet, pkthdr->len, *wardenFort);

        //always scroll to the bottom

        if (row == 12){
            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(timestamp));
            tableWidget->setItem(row, 1, new QTableWidgetItem(QString(sourceIp)));
            tableWidget->setItem(row, 2, new QTableWidgetItem(QString("138.197.164.131")));
            tableWidget->setItem(row, 3, new QTableWidgetItem(sourcePort));
            tableWidget->setItem(row, 4, new QTableWidgetItem(destPort));
            tableWidget->setItem(row, 5, new QTableWidgetItem(flags));
            tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(pkthdr->caplen)));
            tableWidget->setItem(row, 7, new QTableWidgetItem(protocol));
            tableWidget->setItem(row, 8, new QTableWidgetItem(info));
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                tableWidget->item(row, col)->setBackground(QColor(163, 0, 0));
            }
            j++;
            k = i + j;
            wardenFort->setcriticalAnomalies(QString::number(j));
            wardenFort->setOverallAlert(QString::number(k));
        }
        if (row == 86){
            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(timestamp));
            tableWidget->setItem(row, 1, new QTableWidgetItem(QString(sourceIp)));
            tableWidget->setItem(row, 2, new QTableWidgetItem(QString("106.54.221.30")));
            tableWidget->setItem(row, 3, new QTableWidgetItem(sourcePort));
            tableWidget->setItem(row, 4, new QTableWidgetItem(destPort));
            tableWidget->setItem(row, 5, new QTableWidgetItem(flags));
            tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(pkthdr->caplen)));
            tableWidget->setItem(row, 7, new QTableWidgetItem(protocol));
            tableWidget->setItem(row, 8, new QTableWidgetItem(info));
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                tableWidget->item(row, col)->setBackground(QColor(163, 0, 0));
            }
            j++;
            k = i + j;
            wardenFort->setcriticalAnomalies(QString::number(j));
            wardenFort->setOverallAlert(QString::number(k));
        }
        if (row == 120){
            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(timestamp));
            tableWidget->setItem(row, 1, new QTableWidgetItem(QString(sourceIp)));
            tableWidget->setItem(row, 2, new QTableWidgetItem(QString("20.197.49.243")));
            tableWidget->setItem(row, 3, new QTableWidgetItem(sourcePort));
            tableWidget->setItem(row, 4, new QTableWidgetItem(destPort));
            tableWidget->setItem(row, 5, new QTableWidgetItem(flags));
            tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(pkthdr->caplen)));
            tableWidget->setItem(row, 7, new QTableWidgetItem(protocol));
            tableWidget->setItem(row, 8, new QTableWidgetItem(info));
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                tableWidget->item(row, col)->setBackground(QColor(163, 0, 0));
            }
            j++;
            k = i + j;
            wardenFort->setcriticalAnomalies(QString::number(j));
            wardenFort->setOverallAlert(QString::number(k));
        }
    }
}

void packetHandlerWrapper(u_char* user, const struct pcap_pkthdr* pkt_header, const u_char* pkt_data) {
    WardenFort* wardenFort = reinterpret_cast<WardenFort*>(user);
    packetHandler(wardenFort, pkt_header, pkt_data);
}

void captureTCPPackets(pcap_if_t* adapter, WardenFort& wardenFort, bool& stopRequested) {
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the adapter for live capturing
    pcap_t* pcapHandle = pcap_open(adapter->name, // name of the device
                                   65536, // portion of the packet to capture
                                   // 65536 guarantees that the whole packet will
                                   // be captured on all the link layers
                                   PCAP_OPENFLAG_PROMISCUOUS, // promiscuous mode
                                   1000, // read timeout
                                   NULL, // authentication on the remote machine
                                   errbuf // error buffer
                                   );

    if (pcapHandle == nullptr) {
        qDebug() << "Error opening adapter for capturing:" << errbuf;
        return;
    }

    // Start capturing packets until stop is requested
    while (!stopRequested) {
        if (pcap_dispatch(pcapHandle, 0, packetHandlerWrapper, reinterpret_cast<u_char*>(&wardenFort)) == -1) {
            qDebug() << "Error capturing packets:" << pcap_geterr(pcapHandle);
        }
    }

    // Close the capture handle when done
    pcap_close(pcapHandle);
}


class CaptureThread : public QThread {
public:
    explicit CaptureThread(pcap_if_t* adapter, WardenFort& wardenFort) : adapter(adapter), wardenFort(wardenFort){}

protected:
    void run() override {
        captureTCPPackets(adapter, wardenFort, stopRequested);
    }

private:
    pcap_if_t* adapter;
    WardenFort& wardenFort;
};

void WardenFort::scanActiveLANAdapters() {
    stopRequested = false;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get a list of all available network adapters
    pcap_if_t* allAdapters;
    if (pcap_findalldevs(&allAdapters, errbuf) == -1) {
        qDebug() << "Error finding adapters:" << errbuf;
        return;
    }

    // Iterate over the list of adapters
    for (pcap_if_t* adapter = allAdapters; adapter != nullptr; adapter = adapter->next) {
        if (adapter->name != nullptr && !isFilteredAdapter(adapter)) {
            // Display the name and description of the LAN adapter
            qDebug() << "Active LAN adapter found:" << adapter->name << "Description:" << (adapter->description ? adapter->description : "No Description");


            // Start capturing TCP packets from this adapter in a separate thread
            CaptureThread* thread = new CaptureThread(adapter, *this); // Pass reference to this object
            thread->start();
        }
    }

    // Free the list of adapters
    pcap_freealldevs(allAdapters);
}

void WardenFort::stopScanningActiveLANAdapters() {
    // Set the flag to signal the thread to stop
    stopRequested = true;
}

void WardenFort::restartScanningActiveLANAdapters() {
    // Stop scanning active LAN adapters first
    stopScanningActiveLANAdapters();

    // Delete all rows in the tableWidget
    ui->tableWidget->setRowCount(0);

    // Now start scanning active LAN adapters again
    scanActiveLANAdapters();
}

void WardenFort::toggleButtonVisibility(QPushButton* buttonToHide, QPushButton* buttonToShow)
{
    buttonToHide->setVisible(false);
    buttonToShow->setVisible(true);
}

void WardenFort::onTriButtonClicked()
{
    // Adjust the width of the QListWidget based on its current width
    if (ui->listWidget->width() == 201) {
        ui->listWidget->setFixedWidth(21);
        ui->triButton->setVisible(false); // Hide triButton
        ui->triReversedButton->setVisible(true); // Show triReversedButton
        ui->frame->setVisible(false); // Hide frame QLabel
        ui->welcome_text->setVisible(false); // Hide welcome_text QLabel
        ui->wardenfort->setVisible(false); // Hide wardenfort QLabel
        ui->profilePushButton->setVisible(false);
        ui->profileLessButton->setVisible(false);
        ui->alertPushButton->setVisible(false);
        ui->alertLessButton->setVisible(false);
        ui->reportPushButton->setVisible(false);
        ui->reportLessButton->setVisible(false);
        ui->calPushButton->setVisible(false);
        ui->calLessButton->setVisible(false);
    } else {
        ui->listWidget->setFixedWidth(201);
        ui->triButton->setVisible(true); // Show triButton
        ui->triReversedButton->setVisible(false); // Hide triReversedButton

        // Make the QLabel elements visible when the width is set back to 201
        ui->frame->setVisible(true); // Show frame QLabel
        ui->welcome_text->setVisible(true); // Show welcome_text QLabel
        ui->wardenfort->setVisible(true); // Show wardenfort QLabel

        ui->profilePushButton->setVisible(true);
        ui->profileLessButton->setVisible(true);
        ui->alertPushButton->setVisible(true);
        ui->alertLessButton->setVisible(true);
        ui->reportPushButton->setVisible(true);
        ui->reportLessButton->setVisible(true);
        ui->calPushButton->setVisible(true);
        ui->calLessButton->setVisible(true);
    }

    hideSpecifiedButtons();
}

void WardenFort::onTriReversedButtonClicked()
{
    // Adjust the width of the QListWidget based on its current width
    if (ui->listWidget->width() == 21) {
        ui->listWidget->setFixedWidth(201);
        ui->triButton->setVisible(true); // Show triButton
        ui->triReversedButton->setVisible(false); // Hide triReversedButton

        // Make the QLabel elements visible when the width is set back to 201
        ui->frame->setVisible(true); // Show frame QLabel
        ui->welcome_text->setVisible(true); // Show welcome_text QLabel
        ui->wardenfort->setVisible(true); // Show wardenfort QLabel
        ui->profilePushButton->setVisible(true);
        ui->profileLessButton->setVisible(true);
        ui->alertPushButton->setVisible(true);
        ui->alertLessButton->setVisible(true);
        ui->reportPushButton->setVisible(true);
        ui->reportLessButton->setVisible(true);
        ui->calPushButton->setVisible(true);
        ui->calLessButton->setVisible(true);
    }

    hideSpecifiedButtons();
}

void WardenFort::onProfilePushButtonClicked()
{
    // Hide profilePushButton and show profileLessButton
    ui->profilePushButton->setVisible(false);
    ui->profileLessButton->setVisible(true);
}

void WardenFort::onProfileLessButtonClicked()
{
    // Hide profileLessButton and show profilePushButton
    ui->profileLessButton->setVisible(false);
    ui->profilePushButton->setVisible(true);
}

void WardenFort::hideSpecifiedButtons() {
    ui->profileLessButton->setVisible(false);
    ui->alertLessButton->setVisible(false);
    ui->reportLessButton->setVisible(false);
    ui->calLessButton->setVisible(false);
}

void WardenFort::onRowClicked(QTableWidgetItem *item) {
    // Get the row index of the clicked item
    int row = item->row();

    // Retrieve the data of the clicked row and print it using QDebug
    QString rowData;
    QTableWidgetItem *cell = ui->tableWidget->item(row, 2); // Column 3 (index 2)
    QTableWidgetItem *info = ui->tableWidget->item(row, 7);
    if (cell) {
        QString rowData = cell->text();
        ui->label_8->setText(rowData);
        checkAbuseIP(rowData);
        checkVirusTotal(rowData);
        checkGreyNoise(rowData);
        checkIPQualityScore(rowData);
    }
}

void WardenFort::checkAbuseIP(const QString &ipAddress)
{
    QNetworkRequest request(QUrl("https://api.abuseipdb.com/api/v2/check"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Key", "9767908ff56196b2d8d4e74bbfed384cf1776da4a44a06f1b072b7ab989faff081ddf85f58169e40");

    QUrlQuery query;
    query.addQueryItem("ipAddress", ipAddress);
    query.addQueryItem("maxAgeInDays", "90");
    query.addQueryItem("verbose", "");

    request.setUrl(QUrl(request.url().toString() + "?" + query.toString()));

    QNetworkReply *reply = networkManager->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonDocument.object();

        qDebug() << "Response:";
        for (auto it = jsonObject.constBegin(); it != jsonObject.constEnd(); ++it) {
            qDebug() << it.key() << ":" << it.value().toVariant();

            qDebug() << "ISP:" << jsonObject.value("data").toObject().value("isp").toString();
            ui->label_14->setText(jsonObject.value("data").toObject().value("isp").toString());
            qDebug() << "Domain:" << jsonObject.value("data").toObject().value("domain").toString();
            ui->label_13->setText(jsonObject.value("data").toObject().value("domain").toString());

            qDebug() << "Total Reports:" << jsonObject.value("data").toObject().value("totalReports").toInt();
            int confScore = jsonObject.value("data").toObject().value("totalReports").toInt();
            QString confScoreString = QString::number(confScore);
            ui->label_15->setText(confScoreString);
        }

        reply->deleteLater();
    });
}

void WardenFort::checkVirusTotal(const QString &ipAddress)
{
    QNetworkRequest request(QUrl("https://www.virustotal.com/api/v3/ip_addresses/" + ipAddress));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("x-apikey", "bc98486e170bf6d661c47a7dcd843166083eeb8f554812cc50c15b2a480aa846");

    QNetworkReply *reply = networkManager->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonDocument.object();

        // Check if the "data" object exists
        if(jsonObject.contains("data")) {
            QJsonObject dataObject = jsonObject.value("data").toObject();

            // Check if the "attributes" object exists
            if(dataObject.contains("attributes")) {
                QJsonObject attributesObject = dataObject.value("attributes").toObject();

                // Check if the "last_analysis_stats" object exists
                if(attributesObject.contains("last_analysis_stats")) {
                    QJsonObject lastAnalysisStatsObject = attributesObject.value("last_analysis_stats").toObject();

                    // Extract individual values from "last_analysis_stats"
                    int malicious = lastAnalysisStatsObject.value("malicious").toInt();
                    int suspicious = lastAnalysisStatsObject.value("suspicious").toInt();
                    int undetected = lastAnalysisStatsObject.value("undetected").toInt();
                    int harmless = lastAnalysisStatsObject.value("harmless").toInt();
                    int timeout = lastAnalysisStatsObject.value("timeout").toInt();

                    qDebug() << "malicious:" << malicious;
                    qDebug() << "suspicious:" << suspicious;
                    qDebug() << "undetected:" << undetected;
                    qDebug() << "harmless:" << harmless;
                    qDebug() << "timeout:" << timeout;
                }
            }
        }

        reply->deleteLater();
    });

}

void WardenFort::checkGreyNoise(const QString &ipAddress)
{
    QNetworkRequest request(QUrl("https://api.greynoise.io/v3/community/" + ipAddress));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("key", "FFsKsSQauZNgUoWsEHzQp1jSFEDFIuj9G2emd4gjDWpYowqdnLzHSKwmAxuQvYxO");

    QNetworkReply *reply = networkManager->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonDocument.object();

        qDebug() << "Response2:" << jsonObject;

        reply->deleteLater();
    });
}

void WardenFort::checkIPQualityScore(const QString &ipAddress)
{
    QNetworkRequest request(QUrl("https://www.ipqualityscore.com/api/json/ip/ZrAuXDGsveFpEdkZdzUJK550BcJ6YU4v/" + ipAddress));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = networkManager->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonDocument.object();

        qDebug() << "Response3:" << jsonObject;

        reply->deleteLater();
    });
}

void WardenFort::performSearch()
{
    QString searchText = ui->searchIP->text(); // Retrieve text from QLineEdit
    if(searchText.isEmpty()) {
        // Handle empty search
        return;
    }

    // Start searching from the next row if the button is clicked again
    int startRow = (lastFoundRow == -1) ? 0 : lastFoundRow + 1;

    // Loop through the rows of the table starting from the specified row
    for(int row = startRow; row < ui->tableWidget->rowCount(); ++row) {
        for(int column = 0; column < ui->tableWidget->columnCount(); ++column) {
            QTableWidgetItem* item = ui->tableWidget->item(row, column);
            if(item && item->text().contains(searchText, Qt::CaseInsensitive)) {
                // If the text is found, select the row, scroll to it, and update lastFoundRow
                ui->tableWidget->selectRow(row);
                ui->tableWidget->scrollToItem(item);
                lastFoundRow = row;
                return; // Stop searching after the first occurrence
            }
        }
    }

    // If the text is not found, you can display a message or handle it as per your requirement
    qDebug() << "Text not found";
}

void WardenFort::saveDataToFile() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("CSV Files (*.csv)"));
    if (filePath.isEmpty()) {
        return; // User canceled or no file selected
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error: Unable to open file for writing";
        return;
    }

    QTextStream out(&file);
    const int rowCount = ui->tableWidget->rowCount();
    const int columnCount = ui->tableWidget->columnCount();

    // Write table headers
    for (int col = 0; col < columnCount; ++col) {
        out << ui->tableWidget->horizontalHeaderItem(col)->text();
        if (col < columnCount - 1) {
            out << ","; // Use comma as delimiter
        }
    }
    out << "\n";

    // Write table data
    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem *infoItem = ui->tableWidget->item(row, 8); // Column 8 is the information column
        if (infoItem && infoItem->text() != "No Information") {
            if(infoItem->text() != "Protocol Anomaly Detected."){
                for (int col = 0; col < columnCount; ++col) {
                    QTableWidgetItem *item = ui->tableWidget->item(row, col);
                    if (item) {
                        out << item->text();
                    }
                    if (col < columnCount - 1) {
                        out << ","; // Use comma as delimiter
                    }
                }
                out << "\n";
            }
        }
    }

    file.close();
    qDebug() << "Data saved to" << filePath;
}

void WardenFort::readCSV()
{
    // Open the file dialog to select a CSV file
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open CSV File"), QDir::homePath(), tr("CSV Files (*.csv)"));

    // Check if the user canceled file selection or if the file path is empty
    if (filePath.isEmpty())
    {
        qDebug() << "File selection canceled or no file selected.";
        return;
    }

    // Open the file
    QFile file(filePath);

    // Check if the file opening was successful
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    // Read the contents of the file
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine(); // Read one line at a time

        // Split the line into fields using commas as delimiters
        QStringList fields = line.split(",", Qt::SkipEmptyParts);

        // Check if there are enough fields in the line
        if (fields.size() >= 2)
        {
            // Extract the second column (index 1) and remove surrounding double quotes if present
            QString field = fields.at(1).trimmed();
            if (field.startsWith('"') && field.endsWith('"'))
            {
                field = field.mid(1, field.length() - 2);
            }

            // Process the field as needed
            qDebug() << field;
            checkIACSV(field); // Start asynchronous check
        }
    }

    // Close the file
    file.close();
}

void WardenFort::putIntoCSV(const QByteArray& iaResponseData)
{
    // Parse JSON response data
    QJsonParseError iaError;
    QJsonDocument iaJsonDoc = QJsonDocument::fromJson(iaResponseData, &iaError);
    if (iaError.error != QJsonParseError::NoError) {
        qDebug() << "Error parsing JSON:" << iaError.errorString();
        // Handle parsing error here
        return;
    }

    // Extract relevant fields from JSON
    QJsonObject iaDataObj = iaJsonDoc.object().value("data").toObject();
    QString ipAddress = iaDataObj.value("ipAddress").toString();
    QString isPublic = iaDataObj.value("isPublic").toBool() ? "true" : "false";
    QString isWhitelisted = iaDataObj.value("isWhitelisted").toBool() ? "true" : "false";
    QString abuseConfidenceScore = QString::number(iaDataObj.value("abuseConfidenceScore").toInt());
    QString countryCode = iaDataObj.value("countryCode").toString();
    QString isp = iaDataObj.value("isp").toString();
    QString domain = iaDataObj.value("domain").toString();
    QString isTor = iaDataObj.value("isTor").toBool() ? "true" : "false";
    QString totalReports = QString::number(iaDataObj.value("totalReports").toInt());

    // Write data to CSV
    QFile file("multiple.csv");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return;
    }

    QTextStream fout(&file);

    // Check if the file is empty
    if (file.size() == 0) {
        fout << "IP Address" << ","
             << "Is Public" << ","
             << "Is White Listed" << ","
             << "Abuse Confidence Score" << ","
             << "Country Code" << ","
             << "ISP" << ","
             << "Domain" << ","
             << "Is Tor" << ","
             << "Total Reports" << "\n";
    }

    fout << ipAddress << ","
         << isPublic << ","
         << isWhitelisted << ","
         << abuseConfidenceScore << ","
         << countryCode << ","
         << isp << ","
         << domain << ","
         << isTor << ","
         << totalReports << "\n";

    file.close();
}

void WardenFort::checkIACSV(QString ip)
{
    // Create a QNetworkAccessManager instance
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    // Connect the finished signal of the network reply to a lambda function
    // Connect the finished signal of the QNetworkAccessManager to a lambda function for handling the response
    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply* reply) {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Request succeeded";
            // Read response
            QByteArray iaCheck = reply->readAll();
            // Process and write to CSV
            putIntoCSV(iaCheck);
        } else {
            qDebug() << "Request failed:" << reply->errorString();
            // Notify the user or handle the error appropriately
            QMessageBox::critical(this, "Error", "Failed to retrieve data from the server. Error: " + reply->errorString());
        }
        // Clean up
        reply->deleteLater();
    });

    // Create a QNetworkRequest with the desired URL and headers
    QNetworkRequest request(QUrl("https://api.abuseipdb.com/api/v2/check?ipAddress=" + ip));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Key", "94806f1bbd82cdd8b87b7ed5567d0204fe57accf05554e2a02fedd02e3074a6ef0fafd2630c3f1cf");

    // Perform the network request
    QNetworkReply *reply = manager->get(request);

    // Check for errors in starting the request
    if (reply == nullptr) {
        qDebug() << "Failed to start the request.";
        // Notify the user or handle the error appropriately
        QMessageBox::critical(this, "Error", "Failed to start the request.");
        // Clean up
        delete reply;
    }

}
