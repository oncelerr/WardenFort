#include "chatswidget.h"
#include "ui_chatswidget.h"

chats::chats(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chats)
{
    ui->setupUi(this);
}

chats::~chats()
{
    delete ui;
}
