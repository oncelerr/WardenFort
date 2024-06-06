#ifndef CUSTOMCALENDARWIDGET_H
#define CUSTOMCALENDARWIDGET_H

#include <QCalendarWidget>
#include <QMap>
#include <QVector>
#include <QDate>

class CustomCalendarWidget : public QCalendarWidget
{
    Q_OBJECT

public:
    CustomCalendarWidget(QWidget *parent = nullptr);

private slots:
    void addEvent(const QDate &date);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QMap<QDate, QVector<QString>> events; // Store events
};

#endif // CUSTOMCALENDARWIDGET_H
