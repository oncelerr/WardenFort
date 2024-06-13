#ifndef CONTACTS_H
#define CONTACTS_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class contacts;
}

class contacts : public QWidget
{
    Q_OBJECT

public:
    explicit contacts(const QString &username, QWidget *parent = nullptr);
    ~contacts();

    QString getLabel() const; // Declaration of method to get label text

private:
    Ui::contacts *ui;
    QLabel *label;
};

#endif // CONTACTS_H
