#ifndef CALENDAR_H
#define CALENDAR_H

#include <QMainWindow>
#include "CustomCalendarWidget.h"

namespace Ui {
class Calendar;
}

class Calendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

private:
    Ui::Calendar *ui;
    CustomCalendarWidget *customWidget;
};

#endif // CALENDAR_H
