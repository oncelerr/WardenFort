#ifndef NOTIFWIDGET_H
#define NOTIFWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QListWidgetItem>
#include "notificationwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class notifWidget; }
QT_END_NAMESPACE

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
    void onDeleteButtonClicked();
    void refreshNotifications(); // Slot for refresh button clicked

private:
    Ui::notifWidget *ui;
    QTimer *timer;
    int currentPage;
    int pageSize;

};

#endif // NOTIFWIDGET_H
