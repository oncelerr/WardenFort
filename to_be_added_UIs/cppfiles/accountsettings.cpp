#include "accountsettings.h"
#include "ui_accountsettings.h"

accountSettings::accountSettings(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::accountSettings)
{
    ui->setupUi(this);
}

accountSettings::~accountSettings()
{
    delete ui;
}
