#ifndef CALENDARNOTIFICATIONS_H
#define CALENDARNOTIFICATIONS_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMap>
#include <QPair>
#include <QDate>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class CalendarNotifications; }
QT_END_NAMESPACE

class CalendarNotifications : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalendarNotifications(QWidget *parent = nullptr);
    ~CalendarNotifications();

private slots:
    void onTriButtonClicked();
    void onTriReversedButtonClicked();
    void onProfilePushButtonClicked();
    void onProfileLessButtonClicked();
    void onAlertPushButtonClicked();
    void onAlertLessButtonClicked();
    void onReportPushButtonClicked();
    void onReportLessButtonClicked();

private:
    Ui::CalendarNotifications *ui;
    QMap<QDate, QList<QPair<QString, QPair<QString, bool>>>> notifications; // Modified to include isImportant

    void addNotification(const QString &date, const QString &time, const QString &text, bool isImportant);
    void updateNotifications();
    void applyDateItemStyles();
    void toggleButtonVisibility(QPushButton* buttonToHide, QPushButton* buttonToShow);
    void hideSpecifiedButtons();  // Declare this function if it is used
};

#endif // CALENDARNOTIFICATIONS_H
