#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H

#include <QDialog>

namespace Ui {
class EventDialog;
}

class EventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EventDialog(QWidget *parent = nullptr);
    ~EventDialog();

    QString getEventTitle() const;
    QString getEventDescription() const;

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::EventDialog *ui;
};

#endif // EVENTDIALOG_H
