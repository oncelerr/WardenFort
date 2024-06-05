#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QMainWindow>

namespace Ui {
class notification;
}

class notification : public QMainWindow
{
    Q_OBJECT

public:
    explicit notification(QWidget *parent = nullptr);
    ~notification();

private:
    Ui::notification *ui;
};

#endif // NOTIFICATION_H
