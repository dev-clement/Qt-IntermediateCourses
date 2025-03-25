#include <QDebug>
#include <QMouseEvent>
#include "filter.hpp"

Filter::Filter(QObject *po_parent): QObject{po_parent}
{}

bool Filter::eventFilter(QObject *po_watched, QEvent *po_event) {
    if (po_event->type() == QMouseEvent::MouseButtonPress ||
        po_event->type() == QMouseEvent::MouseButtonDblClick) {
        qDebug() << "Filter: Event hijacked in filter";
        return true; // Event handled no need to notify original destination !
        // return false; // Event will then be passed away to other widget interested in.
    }
    return QObject::eventFilter(po_watched, po_event);
}
