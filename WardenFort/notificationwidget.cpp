#include "notificationwidget.h"
#include "ui_notificationwidget.h"
#include <QMouseEvent>
#include <QListWidget>
#include <QListWidgetItem>

NotificationWidget::NotificationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationWidget),
    detailsVisible(false)
{
    ui->setupUi(this);
    connect(ui->expandButton, &QPushButton::clicked, this, &NotificationWidget::onExpandButtonClicked);

    // Ensure the detailsFrame is initially hidden
    ui->detailsFrame->setVisible(false);

    // Make sure the button text is empty
    ui->expandButton->setText("");
}

NotificationWidget::~NotificationWidget()
{
    delete ui;
}

void NotificationWidget::setDate(const QString &date) {
    ui->dateLabel->setText(date);
    ui->dateLabel->setVisible(!date.isEmpty());
}

void NotificationWidget::setTime(const QString &time) {
    ui->timeLabel->setText(time);
}

void NotificationWidget::setText(const QString &text) {
    ui->textLabel->setText(text);
}

void NotificationWidget::setDetails(const QString &details) {
    ui->detailsLabel->setText(details);
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
    if (ui->expandButton->geometry().contains(event->pos())) {
        qDebug() << "Push button clicked";
    } else {
        event->ignore();
    }
}

void NotificationWidget::onExpandButtonClicked() {
    detailsVisible = !detailsVisible;
    ui->detailsFrame->setVisible(detailsVisible);

    // Adjust the widget size to accommodate the details
    if (detailsVisible) {
        this->setFixedHeight(this->height() + ui->detailsFrame->sizeHint().height());
    } else {
        this->setFixedHeight(this->height() - ui->detailsFrame->sizeHint().height());
    }

    // Update the size hint of the corresponding QListWidgetItem
    QListWidget* listWidget = qobject_cast<QListWidget*>(this->parent()->parent());
    if (listWidget) {
        for (int i = 0; i < listWidget->count(); ++i) {
            if (listWidget->itemWidget(listWidget->item(i)) == this) {
                QListWidgetItem *item = listWidget->item(i);
                if (item) {
                    item->setSizeHint(this->sizeHint());
                    listWidget->update(); // Trigger a layout update
                }
                break;
            }
        }
    }
}
