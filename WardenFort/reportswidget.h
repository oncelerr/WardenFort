#ifndef REPORTSWIDGET_H
#define REPORTSWIDGET_H

#include <QWidget>

namespace Ui {
class reportsWidget;
}

class reportsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit reportsWidget(QWidget *parent = nullptr);
    ~reportsWidget();


    void setDate(const QString &date);
    void setID(const QString &text);

private:
    Ui::reportsWidget *ui;

signals:
    void buttonClicked();
};

#endif // REPORTSWIDGET_H
