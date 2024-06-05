#include "eventdialog.h"
#include "ui_eventdialog.h"

EventDialog::EventDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventDialog)
{
    ui->setupUi(this);
}

EventDialog::~EventDialog()
{
    delete ui;
}

QString EventDialog::getEventTitle() const
{
    return ui->eventTitleLineEdit->text();
}

QString EventDialog::getEventDescription() const
{
    return ui->eventDescriptionPlainTextEdit->toPlainText(); // Corrected toPlainText() method call
}

void EventDialog::on_okButton_clicked()
{
    accept(); // Accept the dialog
}

void EventDialog::on_cancelButton_clicked()
{
    reject(); // Reject the dialog
}
