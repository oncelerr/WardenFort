#ifndef NOTIFWIDGET_H
#define NOTIFWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QMap>
#include "notificationwidget.h"

namespace Ui {
class notifWidget;
}

class notifWidget : public QWidget
{
    Q_OBJECT

public:
    explicit notifWidget(QWidget *parent = nullptr);
    ~notifWidget();
    void addNotifications(int offset, int limit);

protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;

private slots:
    void updateNotifications();
    void onRightButtonClicked();
    void onLeftButtonClicked();
    void onMainCheckBoxStateChanged(int state);
    void onDeleteButtonClicked();  // Add this line

private:
    Ui::notifWidget *ui;
    QTimer *timer;
    int currentPage;
    int pageSize;
};

#endif // NOTIFWIDGET_H
