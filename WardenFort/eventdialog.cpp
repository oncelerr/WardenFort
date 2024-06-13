#include "eventdialog.h"
#include "ui_eventdialog.h"
#include <QMessageBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidgetItem>
#include <QWidget>
#include <QLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "database.h"
#include "customcalendarwidget.h"

EventDialog::EventDialog(QWidget *parent, const QDate &date, const QStringList &events) :
    QDialog(parent),
    ui(new Ui::EventDialog),
    eventDate(date),
    eventList(events)
{
    ui->setupUi(this);

    // Set up styles for better readability
    setStyleSheet("QDialog { background-color: #2B2B2B; color: white; }"
                  "QLabel { color: white; }"
                  "QPushButton { background-color: #555555; color: white; }"
                  "QPushButton:hover { background-color: #777777; }"
                  "QLineEdit, QPlainTextEdit { background-color: #3C3C3C; color: white; }"
                  "QListWidget { background-color: #3C3C3C; color: white; }");

    // Populate the list widget with existing events
    for (const QString &event : eventList) {
        QListWidgetItem *item = new QListWidgetItem(ui->eventListWidget);
        QWidget *widget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widget);

        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(5);

        QLabel *eventLabel = new QLabel(event, widget);
        eventLabel->setStyleSheet("color: white;");
        layout->addWidget(eventLabel);

        QPushButton *deleteButton = new QPushButton("Delete", widget);
        deleteButton->setStyleSheet("background-color: #FF6347; color: white;");
        connect(deleteButton, &QPushButton::clicked, this, &EventDialog::deleteEvent); // Connect delete button to deleteEvent slot
        layout->addWidget(deleteButton);

        widget->setLayout(layout);
        ui->eventListWidget->addItem(item);
        ui->eventListWidget->setItemWidget(item, widget);
    }
}

EventDialog::~EventDialog()
{
    delete ui;
}

QString EventDialog::getEventTitle() const
{
    return ui->eventTitleLineEdit->text();
}

QString EventDialog::getEventDescription() const
{
    return ui->eventDescriptionPlainTextEdit->toPlainText();
}

void EventDialog::on_okButton_clicked()
{
    emit eventAdded(getEventTitle(), getEventDescription()); // Emit eventAdded signal with the new event information
    accept();
}

void EventDialog::on_cancelButton_clicked()
{
    reject();
}

void EventDialog::deleteEvent()
{
    qDebug() << "deleteEvent triggered"; // Debug statement

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QWidget *widget = button->parentWidget();
        if (widget) {
            qDebug() << "Parent widget found"; // Debug statement

            for (int i = 0; i < ui->eventListWidget->count(); ++i) {
                QListWidgetItem *item = ui->eventListWidget->item(i);
                if (ui->eventListWidget->itemWidget(item) == widget) {
                    qDebug() << "Matching widget found at index" << i; // Debug statement

                    // Remove the event from the internal list
                    QLabel *label = widget->findChild<QLabel*>();
                    if (label) {
                        QString eventTitle = label->text();
                        eventList.removeAll(eventTitle);

                        // Remove the event from the database
                        CustomCalendarWidget *calendar = qobject_cast<CustomCalendarWidget*>(parentWidget());
                        if (calendar) {
                            calendar->deleteEventFromDatabase(eventDate, eventTitle);
                            calendar->handleEventDeleted(eventTitle);
                        }
                    }

                    // Remove the item from the list widget
                    delete item;
                    qDebug() << "Item deleted from UI";

                    // Update the calendar UI in the parent widget
                    CustomCalendarWidget *calendar = qobject_cast<CustomCalendarWidget*>(parentWidget());
                    if (calendar) {
                        calendar->updateCells();
                    }

                    break;
                }
            }
        }
    }
}

// Add event
void EventDialog::addEvent(const QString &title, const QString &description)
{
    qDebug() << "addEvent triggered";

    // Add the event to the database
    QSqlDatabase db = Database::getConnection();
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO calendar (date, events, description) VALUES (:date, :event, :description)");
    query.bindValue(":date", eventDate.toString(Qt::ISODate));
    query.bindValue(":event", title);
    query.bindValue(":description", description);
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }

    db.close();

    // Update the event list
    eventList.append(title);
    qDebug() << "Event added to internal list"; // Debug statement

    // Add the new event to the UI
    QListWidgetItem *item = new QListWidgetItem(ui->eventListWidget);
    QWidget *widget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(widget);

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(5);

    QLabel *eventLabel = new QLabel(title, widget);
    eventLabel->setStyleSheet("color: white;");
    layout->addWidget(eventLabel);

    QPushButton *deleteButton = new QPushButton("Delete", widget);
    deleteButton->setStyleSheet("background-color: #FF6347; color: white;");
    connect(deleteButton, &QPushButton::clicked, this, &EventDialog::deleteEvent);
    layout->addWidget(deleteButton);

    widget->setLayout(layout);
    ui->eventListWidget->addItem(item);
    ui->eventListWidget->setItemWidget(item, widget);

    qDebug() << "Event added to UI"; // Debug statement

    // Update the calendar UI in the parent widget
    CustomCalendarWidget *calendar = qobject_cast<CustomCalendarWidget*>(parentWidget());
    if (calendar) {
        calendar->updateCells();
    }
}
