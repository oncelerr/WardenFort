#ifndef ENTER_H
#define ENTER_H

#include <QDialog>

namespace Ui {
class enter;
}

class forgotpass; // Forward declaration

class enter : public QDialog
{
    Q_OBJECT

public:
    explicit enter(QWidget *parent = nullptr);
    ~enter();

private slots:
    void onFindUsername(const QString& username);
    void onSubmit();
    void onBackButtonClicked();
    void sendEmail(const QString& recipientEmail, const QString& code);
    void generateCode();

private:
    Ui::enter *ui;
    QString m_generatedCode;
};

#endif // ENTER_H
