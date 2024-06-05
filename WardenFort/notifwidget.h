#ifndef NOTIFWIDGET_H
#define NOTIFWIDGET_H

#include <QWidget>

namespace Ui {
class notifWidget;
}

class notifWidget : public QWidget
{
    Q_OBJECT

public:
    explicit notifWidget(QWidget *parent = nullptr);
    ~notifWidget();

private:
    Ui::notifWidget *ui;
};

#endif // NOTIFWIDGET_H
