#include <QDebug>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "colorpicker.hpp"

ColorPicker::ColorPicker(QWidget *po_parent): QWidget{po_parent} {
    initColors();
    initUi();
}

QColor ColorPicker::color() const {
    return _o_color;
}

void ColorPicker::setColor(QColor o_color) {
    _o_color = o_color;
}

void ColorPicker::initColors() {
    _o_colorList << ColorPicker::t_colorMetadata{"Red", Qt::red, 0, 0}
                 << ColorPicker::t_colorMetadata{"Green", Qt::green, 0, 1}
                 << ColorPicker::t_colorMetadata{"Blue", Qt::blue, 0, 2}
                 << ColorPicker::t_colorMetadata{"Cyan", Qt::cyan, 1, 0}
                 << ColorPicker::t_colorMetadata{"Dark Red", Qt::darkRed, 1, 1}
                 << ColorPicker::t_colorMetadata{"Dark Gray", Qt::darkGray, 1, 2}
                 << ColorPicker::t_colorMetadata{"Gray", Qt::gray, 2, 0}
                 << ColorPicker::t_colorMetadata{"Yellow", Qt::yellow, 2, 1}
                 << ColorPicker::t_colorMetadata{"Dark Yellow", Qt::darkYellow, 2, 2};
}

void ColorPicker::_slot_buttonClicked(const QString &o_color) {
    const auto o_css = QString("background-color: %1").arg(o_color);
    _po_label->setStyleSheet(o_css);
    emit _sig_colorChanged(QColor(o_color));
}

QPushButton *ColorPicker::setupButton(const QString &o_text, const QString &o_color, QSizePolicy e_sizePolicy, QWidget *po_parent) {
    QString o_css = QString("background-color: %1").arg(o_color);
    QPushButton *po_btn = new QPushButton(o_text, po_parent);
    po_btn->setSizePolicy(e_sizePolicy);
    po_btn->setStyleSheet(o_css);
    connect(po_btn, &QPushButton::clicked, this, [=](){
        _slot_buttonClicked(o_color);
    });
    return po_btn;
}

void ColorPicker::initUi() {
    QVBoxLayout *po_vBoxLayout = new QVBoxLayout(this);
    _po_gridLayout = new QGridLayout();
    QSizePolicy e_policy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    QList<ColorPicker::t_colorMetadata>::ConstIterator o_cit = _o_colorList.constBegin();
    while (o_cit != _o_colorList.constEnd()) {
        QPushButton *po_btn = setupButton(o_cit->o_name, o_cit->e_color.name(), e_policy);
        _po_gridLayout->addWidget(po_btn, o_cit->i_col, o_cit->i_row);
        ++o_cit;
    }

    _po_label = new QLabel("Color", this);
    _po_label->setFixedHeight(50);
    _po_label->setStyleSheet(QString("background-color: #eeeab6"));

    po_vBoxLayout->addWidget(_po_label);
    po_vBoxLayout->addLayout(_po_gridLayout);
}
