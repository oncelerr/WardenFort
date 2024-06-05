#include "notification.h"
#include "ui_notification.h"

notification::notification(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::notification)
{
    ui->setupUi(this);
}

notification::~notification()
{
    delete ui;
}
