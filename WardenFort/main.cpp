#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "login.h"
#include "wardenfort.h"
#include "reports.h"
#include "database.h"
#include "calendarnotifications.h"
#include "calendar.h"
#include <QSqlError>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // Main thread database connection
    Database::initializeConnection();
    QSqlDatabase db = Database::getConnection();

    if (!db.isOpen()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return 1;
    }

    qDebug() << "Database connected successfully";

    //login login;
    //login.show();
    reports reports;
    //reports.show();


    //CalendarNotifications calendarnotifications;
    //calendarnotifications.show();
    //Calendar calendar;
    //calendar.show();

    WardenFort wardenfort;
    wardenfort.show();

    return a.exec();
}
