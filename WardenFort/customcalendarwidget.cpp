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
    setStyleSheet("QCalendarWidget { background-color: pink; }"
                  "QCalendarWidget QToolButton { color: pink; background-color: pink; }"
                  "QCalendarWidget QToolButton#qt_calendar_prevmonth, "
                  "QCalendarWidget QToolButton#qt_calendar_nextmonth { color: pink; }"
                  "QCalendarWidget QMenu { background-color: #133d52; color: white; }" // Ensuring dropdown text is black
                  "QCalendarWidget QAbstractItemView:enabled { color: black; background-color: #133d52; selection-background-color: pink; }"
                  "QCalendarWidget QAbstractItemView:disabled { color: pink; }"
                  "QCalendarWidget QWidget { font-family: 'Inter'; }");

    // Customize month/year text color and positioning
    QToolButton *monthButton = findChild<QToolButton*>("qt_calendar_monthbutton");
    if (monthButton) {
        monthButton->setStyleSheet("color: white; background-color: #191F32; font-family: 'Inter';");
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
    yearComboBox->setStyleSheet("QComboBox { background-color: pink; color: black; }"
                                "QComboBox QAbstractItemView { background-color: white; color: black; }");

    // Connect QComboBox to update the calendar year
    connect(yearComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &CustomCalendarWidget::updateYear);

    // Hide the week numbers
    setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    // Connect the signal to open the event dialog when a date is selected
    connect(this, &QCalendarWidget::activated, this, &CustomCalendarWidget::addEvent);
}

void CustomCalendarWidget::initializeDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/WardenFort/WardenFort/wardenfort.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS events (date TEXT, event TEXT, description TEXT)")) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
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
        QString dateString = query.value(2).toString().trimmed();
        QDate date = QDate::fromString(dateString, "yyyy-MM-dd");

        if (!date.isValid()) {
            qDebug() << "Invalid date format for:" << dateString;
            continue;
        }

        QString eventTitle = query.value(0).toString();
        QString description = query.value(1).toString();
        events[date].append(eventTitle);

        // Debug output to verify data loading
        qDebug() << "Loaded event:" << eventTitle << "for date:" << date.toString();
    }

    db.close();
}



void CustomCalendarWidget::saveEventToDatabase(const QDate &date, const QString &eventTitle, const QString &eventDescription)
{
    QSqlDatabase db = Database::getConnection();
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO calendar (date, events, description) VALUES (:date, :event, :description)");
    query.bindValue(":date", date.toString(Qt::ISODate));
    query.bindValue(":event", eventTitle);
    query.bindValue(":description", eventDescription);
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
        painter->setBrush(QColor("#FFB6C1")); // Light pink color for selected date background
        painter->setPen(Qt::NoPen);
        painter->drawRect(rect);
        painter->restore();
    }

    // Custom painting code for events
    if (events.contains(date)) {
        painter->save();

        // Draw the event background color only for the event text area
        painter->setBrush(QColor("#FFFFE0")); // Light yellow background
        painter->setPen(Qt::NoPen); // Ensure no border is drawn
        QRect eventRect = rect.adjusted(2, rect.height() - 20, -2, -2); // Draw at the bottom part of the cell
        painter->drawRect(eventRect);

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
    EventDialog dialog(this); // Use EventDialog here
    if (dialog.exec() == QDialog::Accepted) {
        QString eventTitle = dialog.getEventTitle();
        QString eventDescription = dialog.getEventDescription();
        if (!eventTitle.isEmpty()) {
            events[date].append(eventTitle);

            // Highlight the date with no background change
            QTextCharFormat format;
            setDateTextFormat(date, format);

            // Save the event to the database
            saveEventToDatabase(date, eventTitle, eventDescription);

            // Update the calendar to reflect the new event
            updateCells();
        }
    }
}

void CustomCalendarWidget::updateYear(int yearIndex)
{
    int year = yearComboBox->itemText(yearIndex).toInt();
    setSelectedDate(QDate(year, selectedDate().month(), selectedDate().day()));
    setCurrentPage(year, selectedDate().month());
}
