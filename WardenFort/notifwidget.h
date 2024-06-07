#ifndef NOTIFWIDGET_H
#define NOTIFWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class notifWidget;
}

class notifWidget : public QWidget
{
    Q_OBJECT

public:
    explicit notifWidget(QWidget *parent = nullptr);
    ~notifWidget();
    void addNotifications(int offset, int limit);  // Make this method public

protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;

private:
    Ui::notifWidget *ui;
    QTimer *timer;

    int currentPage; // Declare currentPage as a member variable
    int pageSize;    // Declare pageSize as a member variable

private slots:
    void updateNotifications();
    void onRightButtonClicked();
    void onLeftButtonClicked();
};

#endif // NOTIFWIDGET_H
