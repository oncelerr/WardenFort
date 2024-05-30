#include "reportswidget.h"
#include "ui_reportswidget.h"
#include <QMouseEvent>
#include <QDebug>

reportsWidget::reportsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::reportsWidget)
{
    ui->setupUi(this);
}

reportsWidget::~reportsWidget()
{
    delete ui;
}


void reportsWidget::setDate(const QString &date) {
    ui->dateLabel->setText(date);
    ui->dateLabel->setVisible(!date.isEmpty()); // Hide the date label if empty
}

void reportsWidget::setID(const QString &time) {
    ui->idLabel->setText(time);
}
