#ifndef CALENDAR_H
#define CALENDAR_H

#include <QMainWindow>

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
};

#endif // CALENDAR_H
