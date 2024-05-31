#ifndef CALENDARNOTIFICATIONS_H
#define CALENDARNOTIFICATIONS_H

#include <QMainWindow>
#include <QMap>
#include <QListWidgetItem>

namespace Ui {
class CalendarNotifications;
}

class CalendarNotifications : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalendarNotifications(QWidget *parent = nullptr);
    ~CalendarNotifications();

    void addNotification(const QString &date, const QString &time, const QString &text, bool isImportant);
    void updateNotifications();

private:
    Ui::CalendarNotifications *ui;
    QMap<QString, QList<QPair<QString, QString>>> notifications;  // Date -> List of (time, text)
};

#endif // CALENDARNOTIFICATIONS_H
