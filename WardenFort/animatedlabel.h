// animatedlabel.h
#ifndef ANIMATEDLABEL_H
#define ANIMATEDLABEL_H

#include <QLabel>

class AnimatedLabel : public QLabel
{
    Q_OBJECT
public:
    explicit AnimatedLabel(QWidget *parent = nullptr);

signals:
    void clicked(); // Declaration only, no definition here

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // ANIMATEDLABEL_H
