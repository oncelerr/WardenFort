
#ifndef OTP_H
#define OTP_H

#include <QDialog>
#include <QTimer>

    namespace Ui {
    class otp;
}

class otp : public QDialog
{
    Q_OBJECT

public:
    explicit otp(QWidget *parent = nullptr);
    ~otp();

    void setText(const QString& email_show, const QString& hiddenText);
    void setExpectedOTP(const QString& expectedOTP);
    void setName(const QString& expectedName);

signals:
    void successfulLogin(); // Declare successfulLogin signal

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void submitOTP(); // Declare submitOTP slot
    void updateTimer();

private:
    Ui::otp *ui;
    QString expectedOTP;
    QString expectedName;
     QTimer *timer;
     int remainingTimeInSeconds;
};

#endif // OTP_H
