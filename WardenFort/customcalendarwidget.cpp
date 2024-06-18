#include "customcalendarwidget.h"
#include "eventdialog.h"
#include <QToolButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFontDatabase>
#include <QTextCharFormat>
#include <QHBoxLayout>
#include <QSqlError>
#include "database.h"

CustomCalendarWidget::CustomCalendarWidget(QWidget *parent)
    : QCalendarWidget(parent), yearComboBox(new QComboBox(this))
{
    // Initialize the database
    //initializeDatabase();

    loadEvents();

    // Load Inter font
    int fontId = QFontDatabase::addApplicationFont(":/fonts/Inter-Regular.ttf"); // Ensure this path is correct
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    QFont interFont;
    if (!fontFamilies.isEmpty()) {
        interFont = QFont(fontFamilies.at(0));
    } else {
        interFont = QFont("Arial"); // Fallback font
    }

    // Set the stylesheet for customizing the calendar
    setStyleSheet("QCalendarWidget { background-color: #242f83; }"
                  "QCalendarWidget QToolButton { color: pink; background-color: #242f83; }"
                  "QCalendarWidget QToolButton#qt_calendar_prevmonth, "
                  "QCalendarWidget QToolButton#qt_calendar_nextmonth { color: pink; }"
                  "QCalendarWidget QMenu { background-color: black; color: yellow; }" // Ensuring dropdown text is black
                  "QCalendarWidget QAbstractItemView:enabled { color: white; background-color: #191f32; selection-background-color: green; }"
                  "QCalendarWidget QAbstractItemView:disabled { color: pink; }"
                  "QCalendarWidget QWidget { font-family: 'Inter'; }");

    // Customize month/year text color and positioning
    QToolButton *monthButton = findChild<QToolButton*>("qt_calendar_monthbutton");
    if (monthButton) {
        monthButton->setStyleSheet("color: white; background-color: #191f32 ; font-family: 'Inter';");
    }

    // Replace the year button with a QComboBox
    QToolButton *yearButton = findChild<QToolButton*>("qt_calendar_yearbutton");
    if (yearButton) {
        QWidget *navBar = yearButton->parentWidget();
        QHBoxLayout *layout = qobject_cast<QHBoxLayout*>(navBar->layout());
        if (layout) {
            layout->replaceWidget(yearButton, yearComboBox);
        }
        yearButton->hide();
    }

    // Populate the QComboBox with years
    int currentYear = QDate::currentDate().year();
    for (int year = currentYear - 50; year <= currentYear + 50; ++year) {
        yearComboBox->addItem(QString::number(year));
    }
    yearComboBox->setCurrentText(QString::number(currentYear));

    // Set the QComboBox stylesheet to make the background white
    yearComboBox->setStyleSheet("QComboBox { background-color: #191f32; color: white; }"
                                "QComboBox QAbstractItemView { background-color: #191f32; color: white; }");

    // Connect QComboBox to update the calendar year
    connect(yearComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &CustomCalendarWidget::updateYear);

    // Hide the week numbers
    setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    // Connect the signal to open the event dialog when a date is selected
    connect(this, &QCalendarWidget::activated, this, &CustomCalendarWidget::addEvent);

    // Load and set icons for next and previous month buttons
    QToolButton *nextMonthButton = findChild<QToolButton*>("qt_calendar_nextmonth");
    QToolButton *prevMonthButton = findChild<QToolButton*>("qt_calendar_prevmonth");

    if (nextMonthButton && prevMonthButton) {
        QIcon nextIcon("D:/Project/WardenFort/WardenFort/next.png");
        QIcon prevIcon("D:/Project/WardenFort/WardenFort/previous.png");

        nextMonthButton->setIcon(nextIcon);
        prevMonthButton->setIcon(prevIcon);

        nextMonthButton->setStyleSheet("QToolButton#qt_calendar_nextmonth { background-color: #191f32; }");
        prevMonthButton->setStyleSheet("QToolButton#qt_calendar_prevmonth { background-color: #191f32; }");

        nextMonthButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        prevMonthButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    }

    // Connect QComboBox to update the calendar year
    connect(yearComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &CustomCalendarWidget::updateYear);

    // Hide the week numbers
    setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    // Connect the signal to open the event dialog when a date is selected
    connect(this, &QCalendarWidget::activated, this, &CustomCalendarWidget::addEvent);
}

void CustomCalendarWidget::loadEvents()
{
    QSqlDatabase db = Database::getConnection();
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM calendar");
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        return;
    }

    while (query.next()) {
        QString dateString = query.value(1).toString().trimmed();
        QDate date = QDate::fromString(dateString, "yyyy-MM-dd");

        if (!date.isValid()) {
            qDebug() << "Invalid date format for:" << dateString;
            continue;
        }

        QString eventTitle = query.value(0).toString();
        events[date].append(eventTitle);

        // Debug output to verify data loading
        qDebug() << "Loaded event:" << eventTitle << "for date:" << date.toString();
    }

    db.close();
}

void CustomCalendarWidget::saveEventToDatabase(const QDate &date, const QString &eventTitle)
{
    QSqlDatabase db = Database::getConnection();
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO calendar (date, events) VALUES (:date, :event)");
    query.bindValue(":date", date.toString(Qt::ISODate));
    query.bindValue(":event", eventTitle);
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }

    db.close();
}

void CustomCalendarWidget::deleteEventFromDatabase(const QDate &date, const QString &eventTitle)
{
    QSqlDatabase db = Database::getConnection();
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query(db);
    query.prepare("DELETE FROM calendar WHERE date = :date AND events = :event");
    query.bindValue(":date", date.toString(Qt::ISODate));
    query.bindValue(":event", eventTitle);
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }

    db.close();
}

void CustomCalendarWidget::paintCell(QPainter *painter, const QRect &rect, QDate date) const
{
    // Call base class paintCell to ensure default behavior, including drawing the date
    QCalendarWidget::paintCell(painter, rect, date);

    // Custom painting code for the current date
    if (date == QDate::currentDate()) {
        painter->save();
        painter->setBrush(QColor("#ADD8E6")); // Light blue color for current date background
        painter->setPen(Qt::NoPen);
        painter->drawRect(rect);
        painter->restore();
    }

    // Custom painting code for selected date
    if (date == selectedDate()) {
        painter->save();
        painter->setBrush(QColor("#2d2e60")); // Selected Date Background
        painter->setPen(Qt::NoPen);
        painter->drawRect(rect);
        painter->restore();
    }

    // Custom painting code for events
    if (events.contains(date)) {
        painter->save();

        // Draw the event background color only for the event text area
        painter->setBrush(QColor("#3afefe")); // neon blue background
        painter->setPen(Qt::NoPen); // Ensure no border is drawn
        QRect eventRect = rect.adjusted(2, rect.height() - 20, -2, -2); // Draw at the bottom part of the cell
        int radius = 5;
        painter->drawRoundedRect(eventRect, radius, radius);

        // Draw the event text
        painter->setPen(Qt::black); // Set pen color to black for the text
        QFont font = painter->font();
        font.setPointSize(8); // Adjust font size to be smaller
        painter->setFont(font);

        QRect textRect = eventRect.adjusted(2, 2, -2, -2); // Adjust text rect to avoid clipping
        QString eventText = events.value(date).join(", ");

        // Use QTextOption to ensure proper text alignment and handling
        QTextOption textOption;
        textOption.setAlignment(Qt::AlignLeft | Qt::AlignVCenter); // Align text to left and center vertically
        painter->drawText(textRect, eventText, textOption);

        painter->restore();
    }

    // Draw date text after drawing background color
    painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));
}

void CustomCalendarWidget::addEvent(const QDate &date)
{
    QStringList existingEvents = events.value(date);
    EventDialog dialog(this, date, existingEvents); // Pass existing events to the dialog

    // Show the dialog and handle the event creation if accepted
    if (dialog.exec() == QDialog::Accepted) {
        QString eventTitle = dialog.getEventTitle();
        if (!eventTitle.isEmpty()) {
            events[date].append(eventTitle);

            // Save the event to the database
            saveEventToDatabase(date, eventTitle);
        }
    }

    // Update the calendar to reflect any changes, even if the dialog was simply closed
    updateCells();
}

void CustomCalendarWidget::updateCells()
{
    // Ensure the calendar cells are updated properly
    QDate firstDate = this->minimumDate();
    QDate lastDate = this->maximumDate();
    for (QDate date = firstDate; date <= lastDate; date = date.addDays(1)) {
        updateCell(date);
    }
}

void CustomCalendarWidget::handleEventDeleted(const QString &eventTitle)
{
    QDate date = selectedDate();

    qDebug() << "handleEventDeleted called for event:" << eventTitle << "on date:" << date.toString(Qt::ISODate);

    // Check if events map contains the selected date
    if (events.contains(date)) {
        // Remove the event from the events map
        events[date].removeAll(eventTitle);

        // If no more events exist for that date, remove the date entry from events map
        if (events[date].isEmpty()) {
            events.remove(date);

            // Update the database to remove the date if it has no more events
            QSqlDatabase db = Database::getConnection();
            if (!db.open()) {
                QMessageBox::critical(this, "Database Error", db.lastError().text());
                return;
            }

            QSqlQuery query(db);
            query.prepare("DELETE FROM calendar WHERE date = :date");
            query.bindValue(":date", date.toString(Qt::ISODate));
            if (!query.exec()) {
                QMessageBox::critical(this, "Database Error", query.lastError().text());
            }

            db.close();

            qDebug() << "Empty date removed from database:" << date.toString(Qt::ISODate);
        } else {
            // Update the database to reflect the removed event
            QSqlDatabase db = Database::getConnection();
            if (!db.open()) {
                QMessageBox::critical(this, "Database Error", db.lastError().text());
                return;
            }

            QSqlQuery query(db);
            query.prepare("DELETE FROM calendar WHERE events = :event AND date = :date");
            query.bindValue(":event", eventTitle);
            query.bindValue(":date", date.toString(Qt::ISODate));
            if (!query.exec()) {
                QMessageBox::critical(this, "Database Error", query.lastError().text());
            }

            db.close();

            qDebug() << "Event deleted from database:" << eventTitle << "on date:" << date.toString(Qt::ISODate);
        }

        // Update the specific cell for the date
        updateCell(date);

        qDebug() << "Cell updated for date:" << date.toString(Qt::ISODate);
    } else {
        qDebug() << "No events found for date:" << date.toString(Qt::ISODate);
    }
}



void CustomCalendarWidget::updateYear(int yearIndex)
{
    int year = yearComboBox->itemText(yearIndex).toInt();
    setSelectedDate(QDate(year, selectedDate().month(), selectedDate().day()));
    setCurrentPage(year, selectedDate().month());

    // Ensure cells are updated when the year changes
    updateCells();
}

