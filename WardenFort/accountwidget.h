#ifndef ACCOUNTWIDGET_H
#define ACCOUNTWIDGET_H

#include <QWidget>
#include <QEvent>

namespace Ui {
class accountWidget;
}

class accountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit accountWidget(QWidget *parent = nullptr);
    ~accountWidget();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void onChangeButtonClicked();
    void saveProfilePicToDatabase(const QString &filePath);
    void changeEmail();
    void changeUsername();

private:
    Ui::accountWidget *ui;
};

#endif // ACCOUNTWIDGET_H
