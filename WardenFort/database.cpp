#include "database.h"
#include <QSqlError>
#include <QDebug>
#include <QThread>
#include <QString>

QThreadStorage<QSqlDatabase> Database::dbStorage;

void Database::initializeConnection() {
    if (!dbStorage.hasLocalData()) {
        QString connectionName = QString("db_connection_%1").arg(reinterpret_cast<quintptr>(QThread::currentThreadId()));
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName("D:/Project/WardenFort/WardenFort/wardenfort.db");
        if (!db.open()) {
            qDebug() << "Error opening database:" << db.lastError().text();
        }
        dbStorage.setLocalData(db);
    }
}

QSqlDatabase Database::getConnection() {
    initializeConnection();
    return dbStorage.localData();
}
