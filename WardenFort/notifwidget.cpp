#include "notifwidget.h"
#include "ui_notifwidget.h"

notifWidget::notifWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::notifWidget)
{
    ui->setupUi(this);
}

notifWidget::~notifWidget()
{
    delete ui;
}
