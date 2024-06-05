#include "customcalendarwidget.h"
#include "eventdialog.h"
#include <QToolButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFontDatabase>
#include <QTextCharFormat>

CustomCalendarWidget::CustomCalendarWidget(QWidget *parent)
    : QCalendarWidget(parent)
{
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
    setStyleSheet("QCalendarWidget { background-color: white; }"
                  "QCalendarWidget QToolButton { color: white; background-color: #191F32; }"
                  "QCalendarWidget QToolButton#qt_calendar_prevmonth, "
                  "QCalendarWidget QToolButton#qt_calendar_nextmonth { color: green; }"
                  "QCalendarWidget QMenu { background-color: white; color: black; }" // Ensuring dropdown text is black
                  "QCalendarWidget QAbstractItemView:enabled { color: black; background-color: white; selection-background-color: blue; }"
                  "QCalendarWidget QAbstractItemView:disabled { color: gray; }"
                  "QCalendarWidget QWidget { font-family: 'Inter'; }");

    // Customize month/year text color and positioning
    QToolButton *monthButton = findChild<QToolButton*>("qt_calendar_monthbutton");
    if (monthButton) {
        monthButton->setStyleSheet("color: white; background-color: #191F32; font-family: 'Inter';");
    }

    QToolButton *yearButton = findChild<QToolButton*>("qt_calendar_yearbutton");
    if (yearButton) {
        yearButton->setStyleSheet("color: white; background-color: #191F32; font-family: 'Inter';");
    }

    // Hide the week numbers
    setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    // Connect the signal to open the event dialog when a date is selected
    connect(this, &QCalendarWidget::activated, this, &CustomCalendarWidget::addEvent);
}

void CustomCalendarWidget::paintEvent(QPaintEvent *event)
{
    QCalendarWidget::paintEvent(event); // Call base class paintEvent to ensure default behavior
}


void CustomCalendarWidget::addEvent(const QDate &date)
{
    EventDialog dialog(this); // Use EventDialog here
    if (dialog.exec() == QDialog::Accepted) {
        QString eventTitle = dialog.getEventTitle();
        QString eventDescription = dialog.getEventDescription();
        if (!eventTitle.isEmpty()) {
            events[date].append(eventTitle);

            // Highlight the date
            QTextCharFormat format;
            format.setBackground(Qt::yellow);
            setDateTextFormat(date, format);
        }
    }
}


