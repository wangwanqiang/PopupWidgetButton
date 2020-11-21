/**
 * 自定义按钮弹出窗口控件
 *
 * mainwidget.cpp
 * 测试主窗体。
 *
 * FlyWM_
 * GitHub: https://github.com/FlyWM
 * CSDN: https://blog.csdn.net/a844651990
 *
 */
#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "popupwidgetbutton.h"
#include "testpopupwidget.h"
#include <QMoveEvent>
#include <QDebug>
#include <QMenu>

MainWidget::MainWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);


    QFile file(":/qss/qss/my.qss");
    file.open(QFile::ReadOnly);
    QString style = tr(file.readAll());
    this->setStyleSheet(style);

    connect(ui->pushButton, &QPushButton::clicked, [ = ]()
    {
        qDebug() << "Context Menu";




        QAction* action1 = new QAction("checked", this);
        action1->setCheckable(true);
        action1->setChecked(true);

        QAction* action2 = new QAction("unchecked", this);
        action2->setCheckable(true);
        action2->setChecked(false);

        QMenu* menu1 = new QMenu(this);

        for(int i = 0; i < 20; i++)
        {
            QAction* action1 = new QAction("checked", this);
            action1->setCheckable(true);

            if(i % 2 == 1)
            {
                action1->setChecked(true);
            }
            else
            {
                action1->setChecked(false);
            }
            menu1->addAction(action1);
        }

        menu1->setStyleSheet(style);
        menu1->popup(QCursor::pos());
    });

    PopupWidgetButton* pBtn = new PopupWidgetButton(PWB::Vertical, this, this);
    pBtn->move(100, 250);
    TestPopupWidget* pWidget = new TestPopupWidget(this);
    pBtn->setMainWidget(pWidget);
    pBtn->button()->setText("Vertical");

    PopupWidgetButton* pBtn1 = new PopupWidgetButton(PWB::Horizontal, this, this);
    pBtn1->move(180, 250);
    TestPopupWidget* pWidget1 = new TestPopupWidget(this);
    pBtn1->setMainWidget(pWidget1);
    pBtn1->button()->setText("Horizontal");
}

void MainWidget::mouseMoveEvent(QMouseEvent* event)
{
    qDebug() << objectName() << event->pos();

    QList<WSlider*> list = findChildren<WSlider*>();
    foreach (WSlider* aslider, list)
    {
        QPoint cur_pos = ui->widget->mapFromGlobal(QCursor::pos());
        QRect rect = aslider->geometry();
        if(rect.contains(cur_pos))
        {
            int cur_value = aslider->value();
            aslider->setValue(++cur_value);
            qDebug() << "value changed!!" << cur_value;
        }
    }
    //QSlider::mouseMoveEvent(event);
    //releaseMouse();

}

MainWidget::~MainWidget()
{
    delete ui;
}
