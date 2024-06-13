// contacts.cpp

#include "contacts.h"
#include "ui_contacts.h"

contacts::contacts(const QString &username, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contacts)
{
    ui->setupUi(this);
    ui->label->setText(username);
}

contacts::~contacts()
{
    delete ui;
}

QString contacts::getLabel() const
{
    return ui->label->text();
}
