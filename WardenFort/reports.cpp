    #include "reports.h"
    #include "ui_reports.h"
    #include <QSqlQuery>
    #include <QSqlError>
    #include <QSet>
    #include <QRandomGenerator>



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

            // Add a report widget for the current date with a random ID
            QString randomId = QString::number(QRandomGenerator::global()->generate() % 10000);
            addReportsWidget(randomId, date, incidentTypes);
        }
    }

    void reports::addReportsWidget(const QString &date, const QString &id, const QStringList &incidentTypes) {
        // Create a new reportsWidget instance
        reportsWidget *newWidget = new reportsWidget(this);

        // Set properties of the new widget
        newWidget->setDate(id);
        newWidget->setID(date);
        newWidget->setIncidentTypes(incidentTypes.join(", ")); // Set the incident types

        // Get the size hint of the reportsWidget
        QSize sizeHint = newWidget->sizeHint();

        // Add the widget to the QListWidget
        QListWidgetItem *item = new QListWidgetItem(ui->widgetList);
        ui->widgetList->setItemWidget(item, newWidget);

        // Set the size hint of the QListWidgetItem to match the size hint of the reportsWidget
        item->setSizeHint(sizeHint);
    }


    QMap<QString, QStringList> reports::getUniqueDatesAndIncidentTypes() {
        QMap<QString, QStringList> uniqueDatesAndIncidentTypes;

        // Prepare the SQL query to retrieve distinct dates and incident types from the database
        QSqlQuery query(QSqlDatabase::database()); // Use the existing database connection
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
