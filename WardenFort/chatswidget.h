#ifndef CHATSWIDGET_H
#define CHATSWIDGET_H

#include <QWidget>
#include <QWebSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class chats; }
QT_END_NAMESPACE

class chats : public QWidget {
    Q_OBJECT

public:
    explicit chats(QWidget *parent = nullptr);
    ~chats();

private slots:
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(const QString &message);
    void onSendButtonClicked();

private:
    Ui::chats *ui;
    QWebSocket *webSocket;
};

#endif // CHATSWIDGET_H
