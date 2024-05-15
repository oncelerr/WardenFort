// WardenFort.h
#ifndef WARDENFORT_H
#define WARDENFORT_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class WardenFort; }
QT_END_NAMESPACE

class WardenFort : public QMainWindow
{
    Q_OBJECT

public:
    void toggleButtonVisibility(QPushButton* buttonToHide, QPushButton* buttonToShow);
    WardenFort(QWidget* parent = nullptr);
    ~WardenFort();
    void settrafficAnomalies(const QString& text);
    void setcriticalAnomalies(const QString& text);
    void setOverallAlert(const QString& text);
    void setLabelText1(const QString& text);
    QTableWidget* getTableWidget(); // Getter method for tableWidget
    void scanActiveLANAdapters(); // Corrected declaration
    void setWelcomeText(const QString& text);
    void toggleButtons();
    void handleScrollBarValueChange(int value);
    void onRowClicked(QTableWidgetItem *item);
    void checkAbuseIP(const QString &ipAddress);
    void onNetworkReply(QNetworkReply *reply);
    void onNetworkError(QNetworkReply::NetworkError code);
    void checkVirusTotal(const QString &ipAddress);
    void checkGreyNoise(const QString &ipAddress);
    void checkIPQualityScore(const QString &ipAddress);

private slots:
    void onTriButtonClicked();
    void onTriReversedButtonClicked();
    void onProfilePushButtonClicked();
    void onProfileLessButtonClicked();

signals:
    void networkError(QNetworkReply::NetworkError error);

private:
    Ui::WardenFort* ui;
    QNetworkAccessManager *manager;
    QNetworkAccessManager *networkManager;
    void on_passwordButton_released();
    void on_accountButton_released();
    void on_logoutButton_released();
    void hideSpecifiedButtons();
    void sendRequestToChatGPT(const QString &inputText);
    QString extractResponseText(const QJsonDocument &responseJson);
};

#endif // WARDENFORT_H
