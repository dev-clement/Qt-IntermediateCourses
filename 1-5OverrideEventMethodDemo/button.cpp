#include <QDebug>
#include <QEvent>
#include "button.hpp"

Button::Button(QWidget *po_parent): QPushButton{po_parent} {}

bool Button::event(QEvent *po_event) {
    if (po_event->type() == QEvent::MouseButtonPress ||
        po_event->type() == QEvent::MouseButtonDblClick) {
        qDebug() << "Button: mouse press or doubleclick detected";
        // If you are commenting this without calling the parent::event method
        // you won't keep checking other widget for the event to notify other
        // widget than the one you are actually inside.
        // return false;
    }
    return QPushButton::event(po_event);
}
