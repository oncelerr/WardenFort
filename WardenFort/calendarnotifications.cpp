#include "calendarnotifications.h"
#include "ui_calendarnotifications.h"
#include "notificationwidget.h"
#include <QDate>

CalendarNotifications::CalendarNotifications(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalendarNotifications)
{
    ui->setupUi(this);

    // Example notifications
    addNotification("2024-01-05", "3:15 AM", "SEVERE DATA BREACH EXPOSED", true);
    addNotification("2024-01-05", "3:13 PM", "DATA RETRIEVED", false);
    addNotification("2024-01-06", "4:00 PM", "NEW SECURITY FOR DATA", false);
    addNotification("2024-01-07", "1:30 PM", "Meeting for all department will be held at Seminar room A and B", false);
    addNotification("2024-01-07", "9:00 AM", "SCHEDULED MEETING", false);
    addNotification("2024-01-08", "10:00 AM", "HAPPY BIRTHDAY JAE HYUNG!", false);

    updateNotifications();

    // Sidebar setup
    ui->listWidget->setFixedWidth(201);
    ui->triReversedButton->setVisible(false);

    // Initially hide "less" buttons
    ui->profileLessButton->setVisible(false);
    ui->alertLessButton->setVisible(false);
    ui->reportLessButton->setVisible(false);

    // Connect the clicked() signals of the buttons to their respective slots
    connect(ui->triButton, &QPushButton::clicked, this, &CalendarNotifications::onTriButtonClicked);
    connect(ui->triReversedButton, &QPushButton::clicked, this, &CalendarNotifications::onTriReversedButtonClicked);
    connect(ui->profilePushButton, &QPushButton::clicked, this, &CalendarNotifications::onProfilePushButtonClicked);
    connect(ui->profileLessButton, &QPushButton::clicked, this, &CalendarNotifications::onProfileLessButtonClicked);
    connect(ui->alertPushButton, &QPushButton::clicked, this, &CalendarNotifications::onAlertPushButtonClicked);
    connect(ui->alertLessButton, &QPushButton::clicked, this, &CalendarNotifications::onAlertLessButtonClicked);
    connect(ui->reportPushButton, &QPushButton::clicked, this, &CalendarNotifications::onReportPushButtonClicked);
    connect(ui->reportLessButton, &QPushButton::clicked, this, &CalendarNotifications::onReportLessButtonClicked);
}

CalendarNotifications::~CalendarNotifications()
{
    delete ui;
}

void CalendarNotifications::addNotification(const QString &date, const QString &time, const QString &text, bool isImportant) {
    QDate qDate = QDate::fromString(date, "yyyy-MM-dd");
    notifications[qDate].append(qMakePair(time, qMakePair(text, isImportant)));
    updateNotifications();
}

void CalendarNotifications::updateNotifications() {
    ui->notificationList->clear();

    for (auto it = notifications.begin(); it != notifications.end(); ++it) {
        QDate date = it.key();
        QString dateString = date.toString("dddd, MMM d");
        QList<QPair<QString, QPair<QString, bool>>> notifList = it.value();

        // Add date item
        QListWidgetItem *dateItem = new QListWidgetItem(dateString);
        dateItem->setData(Qt::UserRole, true); // Mark as date item
        dateItem->setFlags(dateItem->flags() & ~Qt::ItemIsSelectable);
        ui->notificationList->addItem(dateItem);

        // Add notifications for the date
        /*for (const auto &notif : notifList) {
            QString time = notif.first;
            QString text = notif.second.first;
            bool isImportant = notif.second.second;

            NotificationWidget *widget = new NotificationWidget();
            widget->setDate("");
            widget->setTime(time);
            widget->setText(isImportant ? "<span style='color:red;'>" + text + "</span>" : text);
            widget->setImportant(isImportant);

            QListWidgetItem *item = new QListWidgetItem(ui->notificationList);
            item->setSizeHint(widget->sizeHint());

            ui->notificationList->addItem(item);
            ui->notificationList->setItemWidget(item, widget);
        }*/
    }

    applyDateItemStyles();
}

void CalendarNotifications::applyDateItemStyles() {
    for (int i = 0; i < ui->notificationList->count(); ++i) {
        QListWidgetItem *item = ui->notificationList->item(i);
        if (item->data(Qt::UserRole).toBool()) {  // Check if this item is a date item
            //item->setBackground(Qt::darkCyan);

            // Set custom foreground color
            QColor customColor(1, 253, 245);  // RGB values for #01FDF5
            item->setForeground(customColor);

            // Set the font to Inter, size 16, and bold
            QFont font("Inter", 10);
            font.setBold(true);
            item->setFont(font);
        }
    }
}

void CalendarNotifications::toggleButtonVisibility(QPushButton* buttonToHide, QPushButton* buttonToShow)
{
    buttonToHide->setVisible(false);
    buttonToShow->setVisible(true);
}

void CalendarNotifications::onTriButtonClicked()
{
    if (ui->listWidget->width() == 201) {
        ui->listWidget->setFixedWidth(21);
        ui->triButton->setVisible(false); // Hide triButton
        ui->triReversedButton->setVisible(true); // Show triReversedButton
        ui->frame->setVisible(false); // Hide frame QLabel
        ui->welcome_text->setVisible(false); // Hide welcome_text QLabel
        ui->wardenfort->setVisible(false); // Hide wardenfort QLabel
        ui->profilePushButton->setVisible(false);
        ui->profileLessButton->setVisible(false);
        ui->alertPushButton->setVisible(false);
        ui->alertLessButton->setVisible(false);
        ui->reportPushButton->setVisible(false);
        ui->reportLessButton->setVisible(false);
        ui->calPushButton->setVisible(false);
        //ui->calLessButton->setVisible(false);
    } else {
        ui->listWidget->setFixedWidth(201);
        ui->triButton->setVisible(true); // Show triButton
        ui->triReversedButton->setVisible(false); // Hide triReversedButton

        // Make the QLabel elements visible when the width is set back to 201
        ui->frame->setVisible(true); // Show frame QLabel
        ui->welcome_text->setVisible(true); // Show welcome_text QLabel
        ui->wardenfort->setVisible(true); // Show wardenfort QLabel

        ui->profilePushButton->setVisible(true);
        ui->profileLessButton->setVisible(true);
        ui->alertPushButton->setVisible(true);
        ui->alertLessButton->setVisible(true);
        ui->reportPushButton->setVisible(true);
        ui->reportLessButton->setVisible(true);
        ui->calPushButton->setVisible(true);
        //ui->calLessButton->setVisible(true);
    }

    hideSpecifiedButtons();
}

void CalendarNotifications::onTriReversedButtonClicked()
{
    if (ui->listWidget->width() == 21) {
        ui->listWidget->setFixedWidth(201);
        ui->triButton->setVisible(true); // Show triButton
        ui->triReversedButton->setVisible(false); // Hide triReversedButton

        // Make the QLabel elements visible when the width is set back to 201
        ui->frame->setVisible(true); // Show frame QLabel
        ui->welcome_text->setVisible(true); // Show welcome_text QLabel
        ui->wardenfort->setVisible(true); // Show wardenfort QLabel
        ui->profilePushButton->setVisible(true);
        ui->profileLessButton->setVisible(true);
        ui->alertPushButton->setVisible(true);
        ui->alertLessButton->setVisible(true);
        ui->reportPushButton->setVisible(true);
        ui->reportLessButton->setVisible(true);
        ui->calPushButton->setVisible(true);
        //ui->calLessButton->setVisible(true);
    } else {
        ui->listWidget->setFixedWidth(21);
        ui->triButton->setVisible(false); // Hide triButton
        ui->triReversedButton->setVisible(true); // Show triReversedButton
        ui->frame->setVisible(false); // Hide frame QLabel
        ui->welcome_text->setVisible(false); // Hide welcome_text QLabel
        ui->wardenfort->setVisible(false); // Hide wardenfort QLabel
        ui->profilePushButton->setVisible(false);
        ui->profileLessButton->setVisible(false);
        ui->alertPushButton->setVisible(false);
        ui->alertLessButton->setVisible(false);
        ui->reportPushButton->setVisible(false);
        ui->reportLessButton->setVisible(false);
        ui->calPushButton->setVisible(false);
        //ui->calLessButton->setVisible(false);
    }

    hideSpecifiedButtons();
}

void CalendarNotifications::onProfilePushButtonClicked()
{
    toggleButtonVisibility(ui->profilePushButton, ui->profileLessButton);
}

void CalendarNotifications::onProfileLessButtonClicked()
{
    toggleButtonVisibility(ui->profileLessButton, ui->profilePushButton);
}

void CalendarNotifications::onAlertPushButtonClicked()
{
    toggleButtonVisibility(ui->alertPushButton, ui->alertLessButton);
}

void CalendarNotifications::onAlertLessButtonClicked()
{
    toggleButtonVisibility(ui->alertLessButton, ui->alertPushButton);
}

void CalendarNotifications::onReportPushButtonClicked()
{
    toggleButtonVisibility(ui->reportPushButton, ui->reportLessButton);
}

void CalendarNotifications::onReportLessButtonClicked()
{
    toggleButtonVisibility(ui->reportLessButton, ui->reportPushButton);
}


void CalendarNotifications::hideSpecifiedButtons() {
    // Implement the logic to hide specified buttons here
}

