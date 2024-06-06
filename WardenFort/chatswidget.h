#ifndef CHATSWIDGET_H
#define CHATSWIDGET_H

#include <QWidget>

namespace Ui {
class chats;
}

class chats : public QWidget
{
    Q_OBJECT

public:
    explicit chats(QWidget *parent = nullptr);
    ~chats();

private:
    Ui::chats *ui;
};

#endif // CHATSWIDGET_H
