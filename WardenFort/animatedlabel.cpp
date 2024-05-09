// animatedlabel.cpp
#include "animatedlabel.h"
#include <QMouseEvent>

AnimatedLabel::AnimatedLabel(QWidget *parent) : QLabel(parent) {}

void AnimatedLabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

