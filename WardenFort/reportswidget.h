#ifndef REPORTSWIDGET_H
#define REPORTSWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QPainter>
#include <QPrinter>
namespace Ui {
class reportsWidget;
}

class reportsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit reportsWidget(QWidget *parent = nullptr);
    ~reportsWidget();

    void setDate(const QString &date);
    void setID(const QString &time);
    void setIncidentTypes(const QString &types);

private:
    Ui::reportsWidget *ui;
    void createPDFWithTemplate(const QString &fileName, const QString &filePath, const QString &reportedDate);
    void print();

    QString reportedDate;
    QString incidentTypes;

};


#endif // REPORTSWIDGET_H
