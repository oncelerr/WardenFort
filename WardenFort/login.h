#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "otp.h"
#include "signup.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class login;
}
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    void generateCode();
    void sendEmail(const QString& recipientEmail, const QString& code);
    void resubMail();
    void openEnterWindow();
    void hideLoginFrame();

private slots:
    void on_loginButton_clicked();
    void on_eye_open_clicked();
    void on_eye_closed_clicked();
    void on_signup_button_clicked();
    void on_forgot_pass_clicked();

private:
    Ui::login *ui;
    otp *otpWindow;
    QString m_generatedCode;

private slots:
    void on_typePASS_box_returnPressed();
    void openAlertNotif();

signals:
    void enterPasswordClicked();

};

#endif // LOGIN_H
