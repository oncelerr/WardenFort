#include "otp.h"
#include "ui_otp.h"
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>

otp::otp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otp),
    remainingTimeInSeconds(120) // Initialize remaining time to 2 minutes (120 seconds)
{
    qDebug() << "OTP Dialog Constructor Called";
    ui->setupUi(this);

    // Install event filter on QTextEdit boxes to handle key events
    ui->text1->installEventFilter(this);
    ui->text2->installEventFilter(this);
    ui->text3->installEventFilter(this);
    ui->text4->installEventFilter(this);
    ui->text5->installEventFilter(this);
    ui->text6->installEventFilter(this);

    // Connect the "Enter" key press event to submitOTP slot
    connect(ui->text6, &QTextEdit::textChanged, this, &otp::submitOTP);

    // Create and start the timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &otp::updateTimer);
    timer->start(1000); // Timer ticks every second
    updateTimer(); // Update the timer label initially

    if(!timer->isActive()){
        QMessageBox::warning(this, "Time's Up", "The OTP entry time has expired.");
    }
}

otp::~otp()
{
    delete ui;
}

void otp::setText(const QString& email_show, const QString& hiddenText) {
    ui->email_show->setText(hiddenText);
}

void otp::setExpectedOTP(const QString& expectedOTP) {
    this->expectedOTP = expectedOTP;
}

void otp::setName(const QString& expectedName) {
    this->expectedName = expectedName;
}

void otp::submitOTP() {
    QString enteredOTP = ui->text1->toPlainText() + ui->text2->toPlainText() +
                         ui->text3->toPlainText() + ui->text4->toPlainText() +
                         ui->text5->toPlainText() + ui->text6->toPlainText();

    if (enteredOTP == expectedOTP) {
        qDebug() << "OTP is correct!";
        emit successfulLogin();
        this->close();
    } else {
        qDebug() << "Incorrect OTP!";
    }
}

bool otp::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->text1 || obj == ui->text2 || obj == ui->text3 ||
        obj == ui->text4 || obj == ui->text5 || obj == ui->text6) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            QString text = keyEvent->text();
            if (!text.isEmpty() && text.at(0).isDigit()) {
                QTextEdit *edit = qobject_cast<QTextEdit*>(obj);
                QString currentText = edit->toPlainText();
                if (currentText.size() < 1) {
                    return false;
                } else {
                    return true;
                }
            } else if (keyEvent->key() == Qt::Key_Tab || keyEvent->key() == Qt::Key_Backtab) {
                QTextEdit *edit = qobject_cast<QTextEdit*>(obj);
                QList<QTextEdit*> textEditList = { ui->text1, ui->text2, ui->text3, ui->text4, ui->text5, ui->text6 };
                int currentIndex = textEditList.indexOf(edit);
                if (keyEvent->key() == Qt::Key_Tab) {
                    currentIndex = (currentIndex + 1) % textEditList.size(); // Move to the next box
                } else { // Shift+Tab
                    currentIndex = (currentIndex - 1 + textEditList.size()) % textEditList.size(); // Move to the previous box
                }
                QTextEdit *nextTextEdit = textEditList[currentIndex];
                if (nextTextEdit) {
                    nextTextEdit->setFocus();
                }
                return true; // We handled the event
            } else if (keyEvent->key() == Qt::Key_Backspace) {
                QTextEdit *edit = qobject_cast<QTextEdit*>(obj);
                QString currentText = edit->toPlainText();
                if (currentText.isEmpty()) {
                    QList<QTextEdit*> textEditList = { ui->text1, ui->text2, ui->text3, ui->text4, ui->text5, ui->text6 };
                    int currentIndex = textEditList.indexOf(edit);
                    if (currentIndex > 0) {
                        QTextEdit *prevTextEdit = textEditList[currentIndex - 1];
                        if (prevTextEdit) {
                            prevTextEdit->setFocus();
                        }
                    }
                }
            }
        }
    }
    return QObject::eventFilter(obj, event);
}

void otp::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Backspace) {
        QTextEdit *currentTextEdit = qobject_cast<QTextEdit*>(focusWidget());
        if (currentTextEdit) {
            QString currentText = currentTextEdit->toPlainText();
            if (!currentText.isEmpty()) {
                currentTextEdit->setText(currentText.left(currentText.size() - 1));
            }
        }
    } else if (event->key() == Qt::Key_Tab || event->key() == Qt::Key_Backtab) {
        QTextEdit *currentTextEdit = qobject_cast<QTextEdit*>(focusWidget());
        if (currentTextEdit) {
            QList<QTextEdit*> textEditList = { ui->text1, ui->text2, ui->text3, ui->text4, ui->text5, ui->text6 };
            int currentIndex = textEditList.indexOf(currentTextEdit);
            if (event->key() == Qt::Key_Tab) {
                if (currentIndex < textEditList.size() - 1) {
                    QTextEdit *nextTextEdit = textEditList[currentIndex + 1];
                    if (nextTextEdit) {
                        nextTextEdit->setFocus();
                    }
                }
            } else { // Shift+Tab
                if (currentIndex > 0) {
                    QTextEdit *prevTextEdit = textEditList[currentIndex - 1];
                    if (prevTextEdit) {
                        prevTextEdit->setFocus();
                    }
                }
            }
        }
    }
}

void otp::updateTimer() {
    // Decrement remaining time and update the timer label
    if (remainingTimeInSeconds > 0) {
        remainingTimeInSeconds--;
        int minutes = remainingTimeInSeconds / 60;
        int seconds = remainingTimeInSeconds % 60;
        QString timeString = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
        ui->timer->setText(timeString);
    } else {
        // Time's up, handle accordingly (e.g., show message, disable submit button)
        timer->stop();
        // Optionally emit a signal or call a function to handle the expiration
        // emit timeExpired();
    }
}
