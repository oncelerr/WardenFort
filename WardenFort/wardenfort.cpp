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
#include "loginsession.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QUrlQuery>

#pragma comment(lib, "Ws2_32.lib")

void showDoSPopup();

QMessageBox *dosPopup = nullptr;
QTimer *flashTimer = nullptr;
bool toggleColor = false;

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
    connect(ui->actionStop, &QAction::triggered, this, &WardenFort::stopScanningActiveLANAdapters);
    connect(ui->actionRestart, &QAction::triggered, this, &WardenFort::restartScanningActiveLANAdapters);

    connect(this, &WardenFort::dosAttackDetected, this, &WardenFort::showDoSPopup);

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

typedef struct ip_address {
    u_char byte1;
    u_char byte2;
    u_char byte3;
    u_char byte4;
} ip_address;

typedef struct ip_header {
    u_char ver_ihl;   // Version (4 bits) + IP header length (4 bits)
    u_char tos;       // Type of service
    u_short tlen;     // Total length
    u_short identification; // Identification
    u_short flags_fo; // Flags (3 bits) + Fragment offset (13 bits)
    u_char ttl;       // Time to live
    u_char proto;     // Protocol
    u_short crc;      // Header checksum
    ip_address saddr; // Source address
    ip_address daddr; // Destination address
    u_int op_pad;     // Option + Padding
} ip_header;

#define IP_RF 0x8000        // Reserved fragment flag
#define IP_DF 0x4000        // Don't fragment flag
#define IP_MF 0x2000        // More fragments flag
#define IP_OFFMASK 0x1FFF   // Mask for fragmenting bits

QString ipAddressToString(const ip_address& addr) {
    return QString("%1.%2.%3.%4").arg(addr.byte1).arg(addr.byte2).arg(addr.byte3).arg(addr.byte4);
}

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

    QString flags;
    if (tcpHeader->th_flags & TH_SYN) flags += "SYN ";
    if (tcpHeader->th_flags & TH_ACK) flags += "ACK ";
    if (tcpHeader->th_flags & TH_FIN) flags += "FIN ";

    QString info = QString("No Information");

    QString protocol = getProtocolName(ih->proto);

    QColor backgroundColor;

    if (protocol == "TCP") {
        const struct my_tcphdr* tcpHeader = reinterpret_cast<const struct my_tcphdr*>(packet + sizeof(ip_header));

        // Check TCP flags to determine the color
        if (tcpHeader->th_flags & TH_SYN) {
            backgroundColor = QColor(44, 75, 66); // lightgreen Established connection (SYN packet)
        } else if (tcpHeader->th_flags & TH_ACK) {
            backgroundColor = QColor(44, 75, 50); //darkgreen ACK packet
        } else if (tcpHeader->th_flags & TH_FIN) {
            backgroundColor = QColor(55, 75, 44); //green FIN packet
        } else {
            backgroundColor = QColor(55, 75, 44); //green Other TCP packets
        }

        // Add threat detection for TCP packets
        if ((tcpHeader->th_flags & TH_SYN) && (tcpHeader->th_flags & TH_ACK)) {
            info = "Threat detected: Possible TCP SYN-ACK scan";
        } else if (tcpHeader->th_flags & TH_RST) {
            info = "Threat detected: TCP Reset (RST) Attack";
        }
    } else if (protocol == "UDP") {
        backgroundColor = QColor(45, 44, 75);  //blue UDP packets

        // Add threat detection for UDP packets
        if (dport == 53) {
            info = "Threat detected: DNS Tunneling";
        }
    } else {
        backgroundColor = QColor(61, 62, 74);  //white Default color for other protocols
    }

    if (protocol == "TCP" || protocol == "UDP"){

        QTableWidget* tableWidget = wardenFort->getTableWidget();
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(timestamp));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString(sourceIp)));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString(destIp)));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(sport)));
        tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(dport)));
        tableWidget->setItem(row, 5, new QTableWidgetItem(flags));
        tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(pkthdr->caplen)));
        tableWidget->setItem(row, 7, new QTableWidgetItem(protocol));
        tableWidget->setItem(row, 8, new QTableWidgetItem(info));

        // Set background color for the entire row
        for (int col = 0; col < tableWidget->columnCount(); ++col) {
            tableWidget->item(row, col)->setBackground(backgroundColor);
        }
    }
}

void WardenFort::showDoSPopup() {
    static QMessageBox *dosPopup = nullptr;
    static QTimer *flashTimer = nullptr;
    static bool toggleColor = false;

    if (!dosPopup) {
        dosPopup = new QMessageBox(this);
        dosPopup->setWindowTitle("Alert: Potential DoS Attack");
        dosPopup->setText("A possible DoS attack has been detected!");
        dosPopup->setIcon(QMessageBox::Warning);
        dosPopup->setStandardButtons(QMessageBox::Ok);
    }

    if (!flashTimer) {
        flashTimer = new QTimer(this);
        connect(flashTimer, &QTimer::timeout, this, []() {
            toggleColor = !toggleColor;
            dosPopup->setStyleSheet(toggleColor ? "background-color: red;" : "background-color: yellow;");
        });
    }

    flashTimer->start(500); // Flash every 500 milliseconds

    if (dosPopup->exec() == QMessageBox::Ok) {
        flashTimer->stop();
        dosPopup->setStyleSheet(""); // Reset to default style
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
                                   65535, // portion of the packet to capture (increase this value)
                                   PCAP_OPENFLAG_PROMISCUOUS, // promiscuous mode
                                   1000, // read timeout
                                   NULL, // authentication on the remote machine
                                   errbuf // error buffer
                                   );

    if (pcapHandle == nullptr) {
        qDebug() << "Error opening adapter for capturing:" << errbuf;
        wardenFort.scanActiveLANAdapters();
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

    // Write table headers to CSV file
    for (int col = 0; col < columnCount; ++col) {
        out << ui->tableWidget->horizontalHeaderItem(col)->text();
        out << ","; // Use comma as delimiter
    }
    out << "Occurrence\n"; // Add the new Occurrence column header

    QMap<QString, QStringList> mergedData;
    QMap<QString, int> occurrenceCount;

    // Collect and merge table data
    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem *infoItem = ui->tableWidget->item(row, 8); // Column 8 is the information column
        if (infoItem && infoItem->text() != "No Information") {
            QString sourceIP = ui->tableWidget->item(row, 1)->text(); // Column 1 is "Source IP"
            QStringList rowData;
            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = ui->tableWidget->item(row, col);
                rowData << (item ? item->text() : "");
            }
            if (mergedData.contains(sourceIP)) {
                QStringList &existingData = mergedData[sourceIP];
                for (int col = 0; col < columnCount; ++col) {
                    if (!existingData[col].contains(rowData[col]) && !rowData[col].isEmpty()) {
                        existingData[col] += "; " + rowData[col];
                    }
                }
                occurrenceCount[sourceIP]++;
            } else {
                mergedData[sourceIP] = rowData;
                occurrenceCount[sourceIP] = 1;
            }

            // Insert data into SQLite database using the existing database connection
            QSqlQuery query(QSqlDatabase::database()); // Use the existing database connection
            query.prepare("INSERT INTO packets (timestamp, sourceIP, destinationIP, sourcePORT, destinationPORT, flags, capLEN, protocol, info, occurrence) "
                          "VALUES (:timestamp, :sourceIP, :destinationIP, :sourcePORT, :destinationPORT, :flags, :capLEN, :protocol, :info, :occurrence)");
            query.bindValue(":timestamp", rowData[0]);
            query.bindValue(":sourceIP", rowData[1]);
            query.bindValue(":destinationIP", rowData[2]);
            query.bindValue(":sourcePORT", rowData[3]);
            query.bindValue(":destinationPORT", rowData[4]);
            query.bindValue(":flags", rowData[5]);
            query.bindValue(":capLEN", rowData[6]);
            query.bindValue(":protocol", rowData[7]);
            query.bindValue(":info", rowData[8]);
            query.bindValue(":occurrence", occurrenceCount[sourceIP]);
            if (!query.exec()) {
                qDebug() << "Error inserting data into database:" << query.lastError().text();
            }
        }
    }

    // Write merged data to CSV file
    QMapIterator<QString, QStringList> it(mergedData);
    while (it.hasNext()) {
        it.next();
        QStringList rowData = it.value();
        for (int col = 0; col < columnCount; ++col) {
            out << rowData[col];
            out << ","; // Use comma as delimiter
        }
        out << occurrenceCount[it.key()] << "\n"; // Write the occurrence count
    }

    file.close();
    qDebug() << "Data saved to" << filePath;
}
