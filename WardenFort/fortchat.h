// fortchat.h
#ifndef FORTCHAT_H
#define FORTCHAT_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class FortChat;
}

class FortChat : public QMainWindow
{
    Q_OBJECT

public:
    explicit FortChat(QWidget *parent = nullptr);
    ~FortChat();

    bool addUser(const QString &username, const QString &password); // Declare addUser method
    bool storeMessage(int senderId, int receiverId, const QString &message); // Declare storeMessage method
    void onLoginSuccessful(const QString &username);


private:
    void initializeDatabase(); // Function to initialize the database

    Ui::FortChat *ui;
    QSqlDatabase db; // Database connection
    QString currentUsername;

};

#endif // FORTCHAT_H
