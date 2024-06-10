#include "notifwidget.h"
#include "ui_notifwidget.h"
#include "notificationwidget.h"
#include "database.h"
#include "globals.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QListWidgetItem>
#include <QDebug>
#include <QDate>
#include <QTime>

notifWidget::notifWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::notifWidget)
    , timer(new QTimer(this)) // Initialize the QTimer
    , currentPage(0) // Initialize current page number
    , pageSize(6) // Set page size to 6
{
    ui->setupUi(this);

    int offset = 0;
    addNotifications(offset, pageSize);

    // Set up the timer to update notifications every second
    connect(timer, &QTimer::timeout, this, &notifWidget::updateNotifications);
    connect(ui->leftBTN, &QPushButton::clicked, this, &notifWidget::onLeftButtonClicked);
    connect(ui->rightBTN, &QPushButton::clicked, this, &notifWidget::onRightButtonClicked);
}

notifWidget::~notifWidget()
{
    delete ui;
}

void notifWidget::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    timer->start(10000); // Start the timer when the widget is shown
}

void notifWidget::hideEvent(QHideEvent *event) {
    QWidget::hideEvent(event);
    timer->stop(); // Stop the timer when the widget is hidden
}

void notifWidget::addNotifications(int offset, int limit) {
    QSqlDatabase db = Database::getConnection(); // Retrieve the correct thread-local database connection
    if (!db.isOpen()) {
        qDebug() << "Database connection is not open";
        return;
    }

    QSqlQuery countQuery(db);
    countQuery.prepare("SELECT COUNT(*) FROM packets WHERE user_id = :user_id");
    countQuery.bindValue(":user_id", loggedInUser.userId);
    if (!countQuery.exec()) {
        qDebug() << "Error executing count query:" << countQuery.lastError().text();
        return;
    }

    // Fetch the count of notifications
    int totalCount = 0;
    if (countQuery.next()) {
        totalCount = countQuery.value(0).toInt();
    }

    // Update the total notifications label
    ui->totalNotif->setText(QString::number(totalCount) + " Alerts");

    QSqlQuery query(db);
    query.prepare("SELECT info, date, time FROM packets WHERE user_id = :user_id ORDER BY date DESC, time DESC LIMIT :limit OFFSET :offset");
    query.bindValue(":user_id", loggedInUser.userId);
    query.bindValue(":limit", limit);
    query.bindValue(":offset", offset);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QString todayDate = QDate::currentDate().toString("yyyy-MM-dd");
    ui->widgetList->clear();

    while (query.next()) {
        QString info = query.value("info").toString();
        QString date = query.value("date").toString();
        QString time = query.value("time").toString();

        QTime parsedTime = QTime::fromString(time, "HH:mm:ss");
        QString formattedTime = parsedTime.toString("HH:mm");

        QDate parsedDate = QDate::fromString(date, "yyyy-MM-dd");
        QString formattedDate = parsedDate.toString("MMMM dd");

        QString timeOrDate;
        if (date == todayDate) {
            timeOrDate = formattedTime;
        } else {
            timeOrDate = formattedDate;
        }

        NotificationWidget *notification = new NotificationWidget(info, timeOrDate);
        QListWidgetItem *item = new QListWidgetItem(ui->widgetList);
        item->setSizeHint(notification->sizeHint());
        ui->widgetList->addItem(item);
        ui->widgetList->setItemWidget(item, notification);
    }
}


void notifWidget::updateNotifications() {
    int offset = 0; // Offset for the first page
    addNotifications(offset, pageSize); // Load the first page
}

// Right button clicked
void notifWidget::onRightButtonClicked() {
    currentPage++; // Increment the page number
    int offset = currentPage * pageSize; // Calculate the offset
    addNotifications(offset, pageSize); // Fetch and display the next set of rows
}

// Left button clicked
void notifWidget::onLeftButtonClicked() {
    if (currentPage > 0) {
        currentPage--; // Decrement the page number if not on the first page
    }
    int offset = currentPage * pageSize; // Calculate the offset
    addNotifications(offset, pageSize); // Fetch and display the previous set of rows
}
