#ifndef PASSWORDSEC_H
#define PASSWORDSEC_H
#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class passwordSec;
}
QT_END_NAMESPACE

class passwordSec : public QMainWindow
{
    Q_OBJECT

public:
    passwordSec(QWidget *parent = nullptr);
    ~passwordSec();
     void getUsername(const QString& text);
    QString username;
    void onChangePasswordButtonClicked();
    void toggleButtonVisibility(QPushButton* buttonToHide, QPushButton* buttonToShow);
    void toggleButtons();


private:
    Ui::passwordSec *ui;
};
#endif // PASSWORDSEC_H
