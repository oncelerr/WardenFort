#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>

namespace Ui {
class reports;
}

class reports : public QWidget
{
    Q_OBJECT

public:
    explicit reports(QWidget *parent = nullptr);
    ~reports();

private:
    Ui::reports *ui;
};

#endif // REPORTS_H
