#include "notificationwidget.h"
#include "ui_notificationwidget.h"

NotificationWidget::NotificationWidget(const QString &text, const QString &timeOrDate, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationWidget)
{
    ui->setupUi(this);
    ui->label->setText(text);      // Assuming there is a QLabel named 'label' in the UI for the notification text
    ui->label_2->setText(timeOrDate); // Assuming there is a QLabel named 'label_2' in the UI for time/date
}

NotificationWidget::~NotificationWidget()
{
    delete ui;
}
