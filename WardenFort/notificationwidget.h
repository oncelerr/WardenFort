#ifndef NOTIFICATIONWIDGET_H
#define NOTIFICATIONWIDGET_H

#include <QWidget>

namespace Ui {
class NotificationWidget;
}

class NotificationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NotificationWidget(QWidget *parent = nullptr);
    ~NotificationWidget();

    void setDate(const QString &date);
    void setTime(const QString &time);
    void setText(const QString &text);
    void setImportant(bool important);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::NotificationWidget *ui;

signals:
    void buttonClicked();
};

#endif // NOTIFICATIONWIDGET_H
