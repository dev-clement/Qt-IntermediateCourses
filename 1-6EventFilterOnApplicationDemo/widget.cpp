#include <QDebug>
#include "widget.hpp"
#include "ui_widget.h"

Widget::Widget(QWidget *po_parent)
    : QWidget(po_parent)
    , _po_ui(new Ui::Widget)
{
    _po_ui->setupUi(this);

    connect(_po_ui->po_btn, &QPushButton::clicked, [=](){
        qDebug() << "Widget: Clicked on a button !!";
    });
}

Widget::~Widget()
{
    delete _po_ui;
}
