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
    void setDetails(const QString &details);
    void setImportant(bool important);

signals:
    void sizeChanged(); // Signal to notify when the size changes

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void onExpandButtonClicked();

private:
    Ui::NotificationWidget *ui;
    bool isImportant;
    bool detailsVisible;

    void applyTextColor();

};

#endif // NOTIFICATIONWIDGET_H
