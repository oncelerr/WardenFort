#ifndef ACCOUNTSETTINGS_H
#define ACCOUNTSETTINGS_H

#include <QMainWindow>

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

private:
    Ui::accountSettings *ui;
};
#endif // ACCOUNTSETTINGS_H
