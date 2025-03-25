#include "widget.hpp"
#include "ui_widget.h"
#include "childbutton.hpp"
#include "childlineedit.hpp"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , _po_ui(new Ui::Widget)
{
    _po_ui->setupUi(this);

    ChildButton *po_btn = new ChildButton(this);
    po_btn->setText("Child button");

    ChildLineEdit *po_childLineEdit = new ChildLineEdit(this);

    _po_ui->verticalLayout->addWidget(po_childLineEdit);
    _po_ui->verticalLayout->addWidget(po_btn);

    connect(po_btn, &ChildButton::clicked, [=](){
        qDebug() << "Button clicked !";
    });

    connect(po_childLineEdit, &ChildLineEdit::textEdited, [=]() {
        qDebug() << "Add character to line edit !";
    });
}

Widget::~Widget()
{
    delete _po_ui;
}
