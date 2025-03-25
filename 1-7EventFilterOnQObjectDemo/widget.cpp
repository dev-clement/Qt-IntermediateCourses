#include "widget.hpp"
#include "ui_widget.h"
#include "keyboardfilter.hpp"

Widget::Widget(QWidget *po_parent): QWidget(po_parent)
    , _po_ui(new Ui::Widget)
    , _po_keyboardFilter(new KeyboardFilter(this)) {
    _po_ui->setupUi(this);
    _po_ui->po_le_NumberForbid->installEventFilter(_po_keyboardFilter);
    connect(_po_ui->po_btnRemoveFilter, &QPushButton::clicked, [=](){
        removeFilters(_po_ui->po_le_NumberForbid);
    });
    connect(_po_ui->po_btnEnableFilter, &QPushButton::clicked, this, [=](){
        installingFilters(_po_ui->po_le_NumberForbid);
    });
}

void Widget::installingFilters(QObject *po_object) {
    qDebug() << "Enabling the filter of the line edit";
    if (!_po_keyboardFilter) {
        _po_keyboardFilter = new KeyboardFilter(this);
    }
    po_object->installEventFilter(_po_keyboardFilter);
}

void Widget::removeFilters(QObject *po_object) {
    qDebug() << "Removing the filter of the line edit";
    po_object->removeEventFilter(_po_keyboardFilter);
}

Widget::~Widget()
{
    _po_ui->po_le_NumberForbid->removeEventFilter(_po_keyboardFilter);
    delete _po_keyboardFilter;
    delete _po_ui;
}
