// chatmessagewidget.cpp
#include "chatmessagewidget.h"

ChatMessageWidget::ChatMessageWidget(const QString &sender, const QString &message, bool isSentByUser, QWidget *parent) :
    QWidget(parent),
    messageLabel(new QLabel)
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    messageLabel->setText(sender + ": " + message);

    if (isSentByUser) {
        layout->addStretch();
        layout->addWidget(messageLabel);
    } else {
        layout->addWidget(messageLabel);
        layout->addStretch();
    }

    setLayout(layout);
}
