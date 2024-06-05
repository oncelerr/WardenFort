#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QThreadStorage>

class Database {
public:
    static void initializeConnection();
    static QSqlDatabase getConnection();

private:
    static QThreadStorage<QSqlDatabase> dbStorage;
};

#endif // DATABASE_H
