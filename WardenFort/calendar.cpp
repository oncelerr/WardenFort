#include "calendar.h"
#include "ui_calendar.h"
#include "customcalendarwidget.h"


Calendar::Calendar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);

    CustomCalendarWidget *customCalendar = new CustomCalendarWidget;
    ui->verticalLayout->addWidget(customCalendar);
}

Calendar::~Calendar() // Define the destructor here
{
    delete ui;
}
