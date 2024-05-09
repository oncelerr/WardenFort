#ifndef ACCOUNTSETTINGS_H
#define ACCOUNTSETTINGS_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class accountSettings;
}
QT_END_NAMESPACE

class accountSettings : public QMainWindow
{
    Q_OBJECT

public:
    accountSettings(QWidget *parent = nullptr);
    ~accountSettings();
    void toggleButtons();
    void toggleButtonVisibility(QPushButton* buttonToHide, QPushButton* buttonToShow);

private:
    Ui::accountSettings *ui;
};
#endif // ACCOUNTSETTINGS_H
