// chatmessagewidget.h
#ifndef CHATMESSAGEWIDGET_H
#define CHATMESSAGEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class ChatMessageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatMessageWidget(const QString &sender, const QString &message, bool isSentByUser, QWidget *parent = nullptr);

private:
    QLabel *messageLabel;
};

#endif // CHATMESSAGEWIDGET_H
