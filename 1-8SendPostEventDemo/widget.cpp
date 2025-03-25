#include <QDebug>
#include <QMouseEvent>
#include "widget.hpp"
#include "ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent)
    , _po_ui(new Ui::Widget)
    , _po_btn(new Button(this))
{
    _po_btn->setText("I am the phoenex king !");
    _po_ui->setupUi(this);

    connect(_po_ui->po_btn, &QPushButton::clicked, [=]() {
        qDebug() << "Button 2 clicked !";
        QMouseEvent *po_mouse = new QMouseEvent(QEvent::MouseButtonPress, QPointF(0, 20), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);

        // send it
        // This code will sent the event imediately it won't
        // be sent to an event queue before

        // if (QApplication::sendEvent(_po_btn, po_mouse)) {
        //     qDebug() << "Event accepted";
        // } else {
        //     qDebug() << "Event declined";
        // }

        // post it
        // This will be posted to the event queue before
        // processing it.

        QApplication::postEvent(_po_btn, po_mouse);
    });
}

Widget::~Widget()
{
    delete _po_ui;
    delete _po_btn;
}
