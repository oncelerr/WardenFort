#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>


QT_BEGIN_NAMESPACE
namespace Ui {
class signup;
}
QT_END_NAMESPACE

class signup : public QMainWindow
{
    Q_OBJECT

public:
    signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signup *ui;
};
#endif // SIGNUP_H
