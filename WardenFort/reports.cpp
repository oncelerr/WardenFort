#include "reports.h"
#include "ui_reports.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSet>
#include <QRandomGenerator>
#include "database.h"


reports::reports(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::reports)
{
    ui->setupUi(this);
    addReportsWidgetsForUniqueDates();
}

reports::~reports()
{
    delete ui;
    // Delete each reportsWidget instance in the list
    for (reportsWidget *widget : reportWidgetsList) {
        delete widget;
    }
}
void reports::addReportsWidgetsForUniqueDates() {
    // Get the map of unique dates and their corresponding incident types from the database
    QMap<QString, QStringList> uniqueDatesAndIncidentTypes = getUniqueDatesAndIncidentTypes();

    // Iterate over each unique date
    for (auto it = uniqueDatesAndIncidentTypes.begin(); it != uniqueDatesAndIncidentTypes.end(); ++it) {
        const QString &date = it.key();
        const QStringList &incidentTypes = it.value();
        getReportIDFromDate(date, incidentTypes);
    }
}

void reports::getReportIDFromDate(const QString &date, const QStringList &incidentTypes) {
    QSqlDatabase db = Database::getConnection();
    QSqlQuery query(db);
    query.prepare("SELECT reportID, reportBY, date, time FROM reports WHERE date = :date");
    query.bindValue(":date", date);
    if (!query.exec()) {
        qDebug() << "Error retrieving reportID from database:" << query.lastError().text();
        // Return -1 to indicate error
    }
    if (query.next()) {
        QString reportID = QString::number(query.value(0).toInt());
        QString reportBy = query.value(1).toString(); // Get reportBy
        QString reportDate = query.value(2).toString(); // Get reportDate
        QString reportTime = query.value(3).toString(); // Get reportTime
        QDateTime datetime = QDateTime::fromString(reportDate + " " + reportTime, "yyyy-MM-dd hh:mm:ss"); // Assuming datetime is in this format
        addReportsWidget(reportID, date, incidentTypes, reportBy, datetime);
    } else {
        qDebug() << "No reportID found for date:" << date;
    }
}



void reports::addReportsWidget(const QString &reportID, const QString &date, const QStringList &incidentTypes, const QString &reportBy, const QDateTime &datetime) {
    // Create a new reportsWidget instance
    reportsWidget *newWidget = new reportsWidget(this);

    // Convert QDateTime to string representation
    QString datetimeString = datetime.toString(Qt::ISODate); // Customize the format as needed

    // Set properties of the new widget
    newWidget->setDate(date);
    newWidget->setID(reportID);
    newWidget->setIncidentTypes(incidentTypes.join(", "));
    newWidget->setReportBy(reportBy); // Set reportBy
    newWidget->setDateTime(datetimeString); // Set datetime as string

    // Get the size hint of the reportsWidget
    QSize sizeHint = newWidget->sizeHint();

    // Add the widget to the QListWidget
    QListWidgetItem *item = new QListWidgetItem(ui->widgetList);
    ui->widgetList->setItemWidget(item, newWidget);

    // Set the size hint of the QListWidgetItem to match the size hint of the reportsWidget
    item->setSizeHint(sizeHint);
     qDebug() << "added widget";
}




QMap<QString, QStringList> reports::getUniqueDatesAndIncidentTypes() {
    QMap<QString, QStringList> uniqueDatesAndIncidentTypes;

    QSqlDatabase db = Database::getConnection();
    QSqlQuery query(db);

    query.prepare("SELECT date, info FROM packets ORDER BY date ASC, info ASC");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error retrieving unique dates and incident types from database:" << query.lastError().text();
        return uniqueDatesAndIncidentTypes; // Return an empty map on error
    } else {
        // Process the query result
        QString currentDate;
        QSet<QString> uniqueIncidentTypes; // Use a set to store unique incident types for each date
        while (query.next()) {
            QString date = query.value("date").toString(); // Retrieve date
            QString incidentType = query.value("info").toString(); // Retrieve incident type

            // If the date changes, store the collected unique incident types and reset for the new date
            if (date != currentDate) {
                if (!currentDate.isEmpty()) {
                    uniqueDatesAndIncidentTypes[currentDate] = uniqueIncidentTypes.values();
                    uniqueIncidentTypes.clear();
                }
                currentDate = date;
            }
            uniqueIncidentTypes.insert(incidentType); // Insert incident type into the set
        }
        // Store the unique incident types for the last date encountered
        if (!currentDate.isEmpty())
            uniqueDatesAndIncidentTypes[currentDate] = uniqueIncidentTypes.values();

        return uniqueDatesAndIncidentTypes;
    }
}
