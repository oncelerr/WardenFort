#include "notificationwidget.h"
#include "ui_notificationwidget.h"
#include <QMouseEvent>
#include <QListWidget>
#include <QListWidgetItem>

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

void NotificationWidget::setDate(const QString &date) {

}

void NotificationWidget::setTime(const QString &time) {

}

void NotificationWidget::setText(const QString &text) {

}

void NotificationWidget::setDetails(const QString &details) {

}

void NotificationWidget::setImportant(bool important) {

}

void NotificationWidget::mousePressEvent(QMouseEvent *event) {

}

void NotificationWidget::onExpandButtonClicked() {

}
