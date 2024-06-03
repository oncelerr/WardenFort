#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>
#include <QList> // Include QList for storing reportsWidget pointers
#include <QSet>

#include "reportswidget.h" // Include reportsWidget header file



namespace Ui {
class reports;
}

class reports : public QWidget
{
    Q_OBJECT

public:
    explicit reports(QWidget *parent = nullptr);
    ~reports();

    // Function to add a reportsWidget instance
    void addReportsWidget(const QString &date, const QString &id, const QStringList &incidentTypes);
     QMap<QString, QStringList> getUniqueDatesAndIncidentTypes();
    void addReportsWidgetsForUniqueDates();


private:
    Ui::reports *ui;
    QList<reportsWidget*> reportWidgetsList; // List to store reportsWidget instances

};

#endif // REPORTS_H
