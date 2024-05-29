#include "calendarnotifications.h"
#include "ui_calendarnotifications.h"
#include "notificationwidget.h"

CalendarNotifications::CalendarNotifications(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalendarNotifications)
{
    ui->setupUi(this);

    // Example notifications
    addNotification("Monday, Jan 5", "3:15AM (Detected)", "SEVERE DATA BREACH EXPOSED", true);
    addNotification("Monday, Jan 5", "3:13PM", "DATA RETRIEVED", false);
    addNotification("Tuesday, Jan 6", "4:00PM", "NEW SECURITY FOR DATA", false);
    addNotification("Wednesday, Jan 7", "", "HAPPY BIRTHDAY JAE HYUNG!", false);
    addNotification("Thursday, Jan 8", "10:00AM", "Meeting for all department will be held at Seminar room A and B", false);

    updateNotifications();
}

CalendarNotifications::~CalendarNotifications()
{
    delete ui;
}

void CalendarNotifications::addNotification(const QString &date, const QString &time, const QString &text, bool isImportant) {
    notifications[date].append(qMakePair(time, text));
    updateNotifications();
}

void CalendarNotifications::updateNotifications() {
    ui->notificationList->clear();

    for (auto it = notifications.begin(); it != notifications.end(); ++it) {
        QString date = it.key();
        QList<QPair<QString, QString>> notifList = it.value();

        // Add date item
        QListWidgetItem *dateItem = new QListWidgetItem(date);
        dateItem->setFlags(dateItem->flags() & ~Qt::ItemIsSelectable);
        ui->notificationList->addItem(dateItem);

        // Add notifications for the date
        for (const auto &notif : notifList) {
            QString time = notif.first;
            QString text = notif.second;

            NotificationWidget *widget = new NotificationWidget();
            widget->setDate("");
            widget->setTime(time);
            widget->setText(text);
            widget->setImportant(false);

            QListWidgetItem *item = new QListWidgetItem(ui->notificationList);
            item->setSizeHint(widget->sizeHint());

            ui->notificationList->addItem(item);
            ui->notificationList->setItemWidget(item, widget);
        }
    }
}
