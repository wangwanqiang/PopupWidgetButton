/**
 * 自定义按钮弹出窗口控件
 *
 * testpopupwidget.cpp
 * 测试用例，自定义弹出的窗体。
 *
 * FlyWM_
 * GitHub: https://github.com/FlyWM
 * CSDN: https://blog.csdn.net/a844651990
 *
 */

#include "testpopupwidget.h"
#include <QStyleOption>
#include <QPainter>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QFile>

TestPopupWidget::TestPopupWidget(QWidget *parent)
    : QWidget(parent)
{
    QLabel *pLabel = new QLabel("This is a popup widget...", this);
    QVBoxLayout *pMainLayout = new QVBoxLayout(this);
   // pLabel->setStyleSheet("QLabel { color: black; }");

    QFile file(":/qss/qss/scroll.qss");
    file.open(QFile::ReadOnly);
    QString style = tr(file.readAll());
    //this->setStyleSheet(style);

    QListWidget * list = new QListWidget();
    for(int i = 0; i<50; i++)
    {
        QString item_str = "Item ->" + QString::number(i);
        list->addItem(item_str);
    }
    list->setStyleSheet(style);

    pMainLayout->addWidget(pLabel);
    pMainLayout->addWidget(list);
}

void TestPopupWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)

    QPainter painter(this);

    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
