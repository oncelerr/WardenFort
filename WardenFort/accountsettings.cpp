#include "accountsettings.h"
#include "ui_accountsettings.h"

accountSettings::accountSettings(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::accountSettings)
{
    ui->setupUi(this);

    // Connect the clicked signal of dd buttons to the toggle function
    connect(ui->dd1, &QPushButton::clicked, this, &accountSettings::toggleButtons);
    connect(ui->dd2, &QPushButton::clicked, this, &accountSettings::toggleButtons);
    connect(ui->dd3, &QPushButton::clicked, this, &accountSettings::toggleButtons);
    connect(ui->dd4, &QPushButton::clicked, this, &accountSettings::toggleButtons);
    connect(ui->dd5, &QPushButton::clicked, this, &accountSettings::toggleButtons);
    connect(ui->dd6, &QPushButton::clicked, this, &accountSettings::toggleButtons);
    connect(ui->dd7, &QPushButton::clicked, this, &accountSettings::toggleButtons);
    connect(ui->dd8, &QPushButton::clicked, this, &accountSettings::toggleButtons);

    // Initially hide dd5 to dd8 buttons
    ui->dd5->setVisible(false);
    ui->dd6->setVisible(false);
    ui->dd7->setVisible(false);
    ui->dd8->setVisible(false);
    ui->profileTab_2->setVisible(false);
    ui->profileTab_3->setVisible(false);
    ui->profileTab_4->setVisible(false);
    ui->profileTab_5->setVisible(false);
    ui->frame_2->setVisible(false);
}

void accountSettings::toggleButtonVisibility(QPushButton* buttonToHide, QPushButton* buttonToShow)
{
    buttonToHide->setVisible(false);
    buttonToShow->setVisible(true);
}

void accountSettings::toggleButtons()
{
    int newY;
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton)
        return; // Safety check

    if (clickedButton == ui->dd1) {
        // Remove the border-top style
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; }");

        toggleButtonVisibility(ui->dd1, ui->dd5);
        //alerts tab
        newY = ui->alertsTab->y() + 90;
        ui->alertsTab->move(ui->alertsTab->x(), newY);
        //reports tab
        newY = ui->reportsTab->y() + 90;
        ui->reportsTab->move(ui->reportsTab->x(), newY);
        //calendarTab
        newY = ui->calendarTab->y() + 90;
        ui->calendarTab->move(ui->calendarTab->x(), newY);

        ui->profileTab_2->setVisible(true);
        ui->frame_2->setVisible(true);
    }

    else if (clickedButton == ui->dd2) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; }");

        toggleButtonVisibility(ui->dd2, ui->dd6);

        //reports tab
        newY = ui->reportsTab->y() + 65;
        ui->reportsTab->move(ui->reportsTab->x(), newY);
        //calendarTab
        newY = ui->calendarTab->y() + 65;
        ui->calendarTab->move(ui->calendarTab->x(), newY);
        ui->profileTab_3->setVisible(true);
        ui->frame_2->setVisible(true);
    }
    else if (clickedButton == ui->dd3) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; }");
        toggleButtonVisibility(ui->dd3, ui->dd7);
        //calendarTab
        newY = ui->calendarTab->y() + 42;
        ui->calendarTab->move(ui->calendarTab->x(), newY);
        ui->profileTab_4->setVisible(true);
        ui->frame_2->setVisible(true);
    }
    else if (clickedButton == ui->dd4) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; }");
        toggleButtonVisibility(ui->dd4, ui->dd8);
        ui->profileTab_5->setVisible(true);
        ui->frame_2->setVisible(true);
    }
    else if (clickedButton == ui->dd5) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; border-top: 1px solid rgb(25, 31, 50);}");

        toggleButtonVisibility(ui->dd5, ui->dd1);
        //alerts tab
        newY = ui->alertsTab->y() - 90;
        ui->alertsTab->move(ui->alertsTab->x(), newY);
        //reports tab
        newY = ui->reportsTab->y() - 90;
        ui->reportsTab->move(ui->reportsTab->x(), newY);
        //calendarTab
        newY = ui->calendarTab->y() - 90;
        ui->calendarTab->move(ui->calendarTab->x(), newY);
        ui->profileTab_2->setVisible(false);
        ui->frame_2->setVisible(false);
    }
    else if (clickedButton == ui->dd6) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; border-top: 1px solid rgb(25, 31, 50);}");

        toggleButtonVisibility(ui->dd6, ui->dd2);
        //reports tab
        newY = ui->reportsTab->y() - 65;
        ui->reportsTab->move(ui->reportsTab->x(), newY);
        //calendarTab
        newY = ui->calendarTab->y() - 65;
        ui->calendarTab->move(ui->calendarTab->x(), newY);
        ui->profileTab_3->setVisible(false);
        ui->frame_2->setVisible(false);
    }
    else if (clickedButton == ui->dd7) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; border-top: 1px solid rgb(25, 31, 50);}");
        toggleButtonVisibility(ui->dd7, ui->dd3);
        //calendarTab
        newY = ui->calendarTab->y() - 42;
        ui->calendarTab->move(ui->calendarTab->x(), newY);
        ui->profileTab_4->setVisible(false);
        ui->frame_2->setVisible(false);
    }
    else if (clickedButton == ui->dd8) {
        ui->profileTab->setStyleSheet("QFrame#profileTab { background-color: rgba(44, 60, 75, 0); border-radius: 0px; border-top: 1px solid rgb(25, 31, 50);}");
        toggleButtonVisibility(ui->dd8, ui->dd4);
        ui->profileTab_5->setVisible(false);
        ui->frame_2->setVisible(false);
    }
}

accountSettings::~accountSettings()
{
    delete ui;
}
