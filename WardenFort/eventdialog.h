#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H

#include "customcalendarwidget.h"
#include <QDialog>
#include <QDate>
#include <QStringList>

// Forward declaration of CustomCalendarWidget class
class CustomCalendarWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class EventDialog; }
QT_END_NAMESPACE

class EventDialog : public QDialog
{
    Q_OBJECT

signals:
    void eventAdded(const QString &title);
    void deleteEventRequested(const QDate &date, const QString &title);

public:
    EventDialog(QWidget *parent = nullptr, const QDate &date = QDate(), const QStringList &events = QStringList());
    ~EventDialog();

    QString getEventTitle() const;
    //QString getEventDescription() const;

public slots:
    void showParent(){
        CustomCalendarWidget *parent = qobject_cast<CustomCalendarWidget*>(parentWidget());
        if(parent)
        {
            qDebug() << "found customcalendar";
            parent->updateCells();
        }
        else{
            qDebug() << "cant detect customcalendar";
        }
    }

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
    void deleteEvent();
    void addEvent(const QString &title);

private:
    Ui::EventDialog *ui;
    QDate eventDate;
    QStringList eventList;
};

#endif // EVENTDIALOG_H
