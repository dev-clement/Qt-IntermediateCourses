#include <QDebug>
#include <QMouseEvent>
#include "button.hpp"

Button::Button(QWidget *po_parent): QPushButton{po_parent}
{}

void Button::mousePressEvent(QMouseEvent *po_event) {
    qDebug() << "Button: Mouse Press at: " << po_event->pos();
    QPushButton::mouseMoveEvent(po_event);
}

void Button::mouseReleaseEvent(QMouseEvent *po_event) {
    qDebug() << "Button: Mouse Release at: " << po_event->pos();
    QPushButton::mouseReleaseEvent(po_event);
}

void Button::mouseMoveEvent(QMouseEvent *po_event) {
    qDebug() << "Button: Mouse Move at: " << po_event->pos();
    QPushButton::mouseMoveEvent(po_event);
}
