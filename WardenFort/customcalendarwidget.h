#ifndef CUSTOMCALENDARWIDGET_H
#define CUSTOMCALENDARWIDGET_H

#include <QCalendarWidget>
#include <QMap>
#include <QVector>
#include <QDate>
#include <QComboBox>
#include <QPainter>
#include <QSqlDatabase>
#include <QSqlQuery>

class CustomCalendarWidget : public QCalendarWidget
{
    Q_OBJECT

public:
    CustomCalendarWidget(QWidget *parent = nullptr);
    void updateCells();
    void clearEventListWidget(); // Declaration of the method to clear events from the UI
    void loadEvents();
    void handleEventDeleted(const QString &eventTitle);
private slots:
    void addEvent(const QDate &date);
    void updateYear(int yearIndex);


public slots:
    void deleteEventFromDatabase(const QDate &date, const QString &eventTitle);

protected:
    void paintCell(QPainter *painter, const QRect &rect, QDate date) const override;

private:
    QMap<QDate, QVector<QString>> events;
    QComboBox *yearComboBox;
    QSqlDatabase db;

    void initializeDatabase();

    void saveEventToDatabase(const QDate &date, const QString &eventTitle, const QString &eventDescription);
    void updateEventInDatabase(const QDate &date, const QString &oldEventTitle, const QString &newEventTitle, const QString &newEventDescription);
};

#endif // CUSTOMCALENDARWIDGET_H
