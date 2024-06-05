#ifndef ACCOUNTWIDGET_H
#define ACCOUNTWIDGET_H

#include <QWidget>

namespace Ui {
class accountWidget;
}

class accountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit accountWidget(QWidget *parent = nullptr);
    ~accountWidget();
    void changeEmail();
    void setGenderComboBox(const QString &gender);
    void changeUsername();

private:
    Ui::accountWidget *ui;
};

#endif // ACCOUNTWIDGET_H
