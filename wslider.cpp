#include "wslider.h"
#include <QDebug>

WSlider::WSlider(QWidget *parent)
    :QSlider(parent)
{
    setMouseTracking(true);
   // mouse
    setAttribute(Qt::WA_TransparentForMouseEvents, true);

}

void WSlider::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<objectName();
    QSlider::mouseMoveEvent(event);
    releaseMouse();

}
