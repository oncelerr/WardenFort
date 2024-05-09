#include "passwordsec.h"
#include "ui_passwordsec.h"

passwordSec::passwordSec(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::passwordSec)
{
    ui->setupUi(this);
}

passwordSec::~passwordSec()
{
    delete ui;
}
