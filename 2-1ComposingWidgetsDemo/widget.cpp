#include <QMessageBox>
#include "widget.hpp"
#include "ui_widget.h"
#include "colorpicker.hpp"

Widget::Widget(QWidget *po_parent) : QWidget(po_parent)
    , _po_ui(new Ui::Widget)
{
    _po_ui->setupUi(this);
    ColorPicker *po_colorPicker = new ColorPicker(this);
    _po_ui->verticalLayout->addWidget(po_colorPicker);
    connect(po_colorPicker, &ColorPicker::_sig_colorChanged, this, &Widget::_slot_colorChanged);
}

void Widget::_slot_colorChanged(QColor e_color) {
    QMessageBox::information(this, "Color changed", QString("Color  changed to: %1").arg(e_color.name()));
}

Widget::~Widget()
{
    delete _po_ui;
}
