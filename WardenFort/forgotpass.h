// forgotpass.h
#ifndef FORGOTPASS_H
#define FORGOTPASS_H

#include <QDialog>
#include <QDateTime>

namespace Ui {
class forgotpass;
}

class forgotpass : public QDialog
{
    Q_OBJECT

public:
    explicit forgotpass(const QString& username, QWidget *parent = nullptr);
    ~forgotpass();
    void setEmail(const QString& email);
    QString maskEmail(const QString& email);
    void onBackButtonClicked();
    void onResetPasswordClicked1();
    void setExpectedOTP(const QString& expectedOTP);
    void changePass();

private slots:
    void updateTimer();

private:
    Ui::forgotpass *ui;
    QDateTime m_expiryTime;
    QString m_username;
    QString m_userEmail;
    QString m_passwordHash; // Store the password hash
    QString expectedOTP;
};

#endif // FORGOTPASS_H
