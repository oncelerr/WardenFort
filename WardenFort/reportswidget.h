#ifndef REPORTSWIDGET_H
#define REPORTSWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QPainter>
#include <QPrinter>

namespace Ui {
class reportsWidget;
}

class reportsWidget : public QWidget {
    Q_OBJECT

public:
    explicit reportsWidget(QWidget *parent = nullptr);
    ~reportsWidget();

    void setDate(const QString &date);
    void setID(const QString &time); // Assuming time is the ID
    void setIncidentTypes(const QString &types);
    void setReportBy(const QString &reportBy); // Corrected parameter type
    void setDateTime(const QString &datetime); //


private:
    Ui::reportsWidget *ui;

    void createPDFWithTemplate(const QString &fileName, const QString &filePath, const QString &reportedDate);
    void print();

    QString reportedDate;
    QString reportedDateTime; // If you need both date and time, you may want to use QDateTime
    QString incidentTypes;
    QString getLocalIpAddress();
    QString location; // If you need location, define and set it
    QString reportedBy; // Corrected member variable name

};

#endif // REPORTSWIDGET_H
