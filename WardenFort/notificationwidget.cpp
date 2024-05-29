#include "notificationwidget.h"
#include "ui_notificationwidget.h"
#include <QMouseEvent>
#include <QDebug>

NotificationWidget::NotificationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationWidget)
{
    ui->setupUi(this);
}

NotificationWidget::~NotificationWidget()
{
    delete ui;
}

void NotificationWidget::setDate(const QString &date) {
    ui->dateLabel->setText(date);
    ui->dateLabel->setVisible(!date.isEmpty()); // Hide the date label if empty
}

void NotificationWidget::setTime(const QString &time) {
    ui->timeLabel->setText(time);
}

void NotificationWidget::setText(const QString &text) {
    ui->textLabel->setText(text);
}

void NotificationWidget::setImportant(bool important) {
    QPalette palette = ui->textLabel->palette();
    if (important) {
        palette.setColor(ui->textLabel->foregroundRole(), Qt::red);
    } else {
        palette.setColor(ui->textLabel->foregroundRole(), Qt::black);
    }
    ui->textLabel->setPalette(palette);
}

void NotificationWidget::mousePressEvent(QMouseEvent *event) {
    if (ui->pushButton->geometry().contains(event->pos())) {
        // Handle push button click
        qDebug() << "Push button clicked";
    } else {
        // Ignore events for other parts of the widget
        event->ignore();
    }
}

