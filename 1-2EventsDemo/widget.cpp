#include <QDebug>
#include <QMenu>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include "widget.hpp"
#include "ui_widget.h"

Widget::Widget(QWidget *po_parent)
    : QWidget(po_parent)
    , _m_ui(new Ui::Widget)
{
    _m_ui->setupUi(this);
}

Widget::~Widget() {
    delete _m_ui;
}

void Widget::mousePressEvent(QMouseEvent *po_event) {
    qDebug() << "Widget, Mouse has been pressed at location: <" << po_event->pos() << ">";
}

void Widget::mouseReleaseEvent(QMouseEvent *po_event) {
    qDebug() << "Widget, Mouse had been released at location: <" << po_event->pos() << ">";
}

void Widget::mouseMoveEvent(QMouseEvent *po_event) {
    qDebug() << "Widget, Mouse has been moved at location: <" << po_event->pos() << ">";
}

void Widget::closeEvent(QCloseEvent *po_event) {
    qDebug() << "Widget, Window is about to close ! " << po_event->isSinglePointEvent();
    po_event->accept();
}

void Widget::contextMenuEvent(QContextMenuEvent *po_event) {
    qDebug() << "Widget, Context menu event !" << po_event->pos() << " " << po_event->reason();
    QMenu *po_menu = new QMenu(this);
    po_menu->addAction(tr("Action 01"));
    po_menu->addAction(tr("Action 02"));

    po_menu->popup(mapToGlobal(po_event->pos()));

    qDebug() << "Happens through: " << (po_event->reason() == 0 ? "by using the mouse" : "by using the keyboard");
}

void Widget::enterEvent(QEnterEvent *) {
    qDebug() << "Widget, Enter event";
}

void Widget::leaveEvent(QEvent *) {
    qDebug() << "Widget, Leave event";
}

void Widget::keyPressEvent(QKeyEvent *po_event) {
    // Displaying the key as an integer value
    qDebug() << "Widget, Key press event: " << po_event->key();
    // Displaying the character value
    qDebug() << "Widget, key press event: " << po_event->text();

    // Check modifiers (shift for example)
    if (po_event->modifiers() & Qt::ShiftModifier) {
        qDebug() << "Widget, Shift modifier press, shift + " << po_event->key() << " giving: " << po_event->text();
    }

    // Check modifiers (Ctrl for example)
    if (po_event->modifiers() & Qt::ControlModifier) {
        qDebug() << "Widget, Ctrl modifier press, ctrl + " << po_event->key() << " giving: " << po_event->text();
    }

    // Check modifiers (Alt for example)
    if (po_event->modifiers() & Qt::AltModifier) {
        qDebug() << "Widget, Ctrl modifier press, alt + " << po_event->key() << " giving: " << po_event->text();
    }

    // Detect on a more professionnal way
    if (po_event->modifiers() & Qt::ShiftModifier) {
        if (po_event->key() == Qt::Key_A) {
            qDebug() << "Widget, Key typed: Shift + a: " << po_event->text();
        }
    }
}

void Widget::wheelEvent(QWheelEvent *po_event) {
    qDebug() << "Widget, Wheel event delta = " << po_event->pixelDelta();
    qDebug() << " x: " << po_event->pixelDelta().x() << ", y" << po_event->pixelDelta().y();
    qDebug() << "Widget, orientation: " << po_event->source();
}

void Widget::paintEvent(QPaintEvent *) {
    qDebug() << "Widget, paintEvent triggered";
}

void Widget::resizeEvent(QResizeEvent *po_event) {
    qDebug() << "Widget, resize event, old size is: " << po_event->oldSize();
    qDebug() << " new size: " << po_event->size();
}


