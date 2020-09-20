#ifndef WSLIDER_H
#define WSLIDER_H

#include <QSlider>

class WSlider:public QSlider
{
    Q_OBJECT
public:
    WSlider(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent * event);
};

#endif // WSLIDER_H
