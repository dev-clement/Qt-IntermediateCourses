#include <QDebug>
#include <QMouseEvent>
#include "childbutton.hpp"

ChildButton::ChildButton(QWidget *po_parent): ParentButton{po_parent} {}

void ChildButton::mousePressEvent(QMouseEvent *po_event) {
    qDebug() << "ChildButton: mousePressEvent on a child button -> " << po_event->pos();
    // Note, if you don't call the parent implementation of the event, this event
    // won't be propagate among parent.
    ParentButton::mousePressEvent(po_event);
}
