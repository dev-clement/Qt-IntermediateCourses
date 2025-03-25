#include <QDebug>
#include "widget.hpp"
#include "ui_widget.h"
#include "button.hpp"

Widget::Widget(QWidget *po_parent): QWidget(po_parent)
    , _po_ui(new Ui::Widget) {
    _po_ui->setupUi(this);

    Button *po_button = new Button(this);
    po_button->setText("Button1");

    _po_ui->verticalLayout->addWidget(po_button);

    connect(po_button, &Button::clicked, [=](){
        qDebug() << "Event has been triggered !!";
    });
}

Widget::~Widget()
{
    delete _po_ui;
}
