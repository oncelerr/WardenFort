#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "login.h"
#include "wardenfort.h"
#include "reports.h"
#include <QSqlError>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/admin/Documents/GitHub/WardenFort/WardenFort/wardenfort.db");

    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return 1;
    }

    qDebug() << "Database connected successfully";

    //login login;
    //login.show();
    reports reports;
    reports.show();

    
       //WardenFort wardenfort;
      //wardenfort.show();
    

    return a.exec();
}
