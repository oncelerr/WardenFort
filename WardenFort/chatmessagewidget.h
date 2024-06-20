#ifndef CHATMESSAGEWIDGET_H
#define CHATMESSAGEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class ChatMessageWidget : public QWidget {
    Q_OBJECT

public:
    explicit ChatMessageWidget(const QString &message, bool isSender, QWidget *parent = nullptr);

private:
    QLabel *messageLabel;
    QHBoxLayout *layout;
};

#endif // CHATMESSAGEWIDGET_H
