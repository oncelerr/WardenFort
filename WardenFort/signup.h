#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class signup; }
QT_END_NAMESPACE

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void onCreateButtonClicked();
    void onBackButtonClicked();
    void onPasswordTextChanged(const QString &password); // Declare the slot for password text change
    void checkEmail();
    void checkUsername();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
