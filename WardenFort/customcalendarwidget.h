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

private slots:
    void addEvent(const QDate &date);
    void updateYear(int yearIndex);

protected:
    void paintCell(QPainter *painter, const QRect &rect, QDate date) const override; // Match the base class signature

private:
    QMap<QDate, QVector<QString>> events; // Store events
    QComboBox *yearComboBox; // Dropdown for year selection
    QSqlDatabase db; // Database connection

    void initializeDatabase();
    void loadEvents();
    void saveEventToDatabase(const QDate &date, const QString &eventTitle, const QString &eventDescription);
    void updateEventInDatabase(const QDate &date, const QString &oldEventTitle, const QString &newEventTitle, const QString &newEventDescription);
    void deleteEventFromDatabase(const QDate &date, const QString &eventTitle);
};

#endif // CUSTOMCALENDARWIDGET_H
