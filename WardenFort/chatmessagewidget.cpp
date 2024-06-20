#include "chatmessagewidget.h"
#include <QLabel>
#include <QHBoxLayout>

ChatMessageWidget::ChatMessageWidget(const QString &message, bool isSender, QWidget *parent)
    : QWidget(parent) {
    messageLabel = new QLabel(message, this);
    messageLabel->setWordWrap(true);
    messageLabel->setStyleSheet("background-color: #252d3c; color: white; border-radius: 10px; padding: 10px;");

    layout = new QHBoxLayout(this);

    if (isSender) {
        layout->addStretch();
        layout->addWidget(messageLabel);
    } else {
        layout->addWidget(messageLabel);
        layout->addStretch();
    }

    setLayout(layout);
}
