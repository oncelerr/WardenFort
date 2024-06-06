#ifndef PASSWORDSECWIDGET_H
#define PASSWORDSECWIDGET_H
#include <QMainWindow>
#include <QPushButton>


#include <QWidget>

namespace Ui {
class passwordSecWidget;
}

class passwordSecWidget : public QWidget
{
    Q_OBJECT

public:
    explicit passwordSecWidget(QWidget *parent = nullptr);
    ~passwordSecWidget();
    void getUsername(const QString& text);
    QString username;
    void onChangePasswordButtonClicked();
    void toggleButtonVisibility(QPushButton* buttonToHide, QPushButton* buttonToShow);
    void toggleButtons();

private:
    Ui::passwordSecWidget *ui;
};

#endif // PASSWORDSECWIDGET_H
