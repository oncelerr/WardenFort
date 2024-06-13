#include "notificationwidget.h"
#include "ui_notificationwidget.h"
#include <QMouseEvent>
#include <QListWidget>
#include <QListWidgetItem>

NotificationWidget::NotificationWidget(const QString &text, const QString &timeOrDate, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationWidget),
    m_info(text) // Initialize m_info with text
{
    ui->setupUi(this);
    ui->label->setText(text);      // Assuming there is a QLabel named 'label' in the UI for the notification text
    ui->label_2->setText(timeOrDate); // Assuming there is a QLabel named 'label_2' in the UI for time/date
}

NotificationWidget::~NotificationWidget()
{
    delete ui;
}

QString NotificationWidget::info() const
{
    return m_info;
}

bool NotificationWidget::isChecked() const
{
    return ui->checkBox->isChecked();
}

void NotificationWidget::setChecked(bool checked)
{
    ui->checkBox->setChecked(checked);
}

void NotificationWidget::setDate(const QString &date) {
    // Implement if needed
}

void NotificationWidget::setTime(const QString &time) {
    // Implement if needed
}

void NotificationWidget::setText(const QString &text) {
    // Implement if needed
}

void NotificationWidget::setDetails(const QString &details) {
    // Implement if needed
}

void NotificationWidget::setImportant(bool important) {
    // Implement if needed
}

void NotificationWidget::mousePressEvent(QMouseEvent *event) {
    // Implement if needed
}

void NotificationWidget::onExpandButtonClicked() {
    // Implement if needed
}
