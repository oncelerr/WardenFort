#ifndef LOGINSESSION_H
#define LOGINSESSION_H

#include <QWidget>

class loginsession
{
public:
    loginsession();
    void sessionStart(const QString username);
    void sessionEnd();
    QString username;
};

#endif // LOGINSESSION_H
