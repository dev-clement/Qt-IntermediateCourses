#include <QDebug>
#include <QKeyEvent>
#include "keyboardfilter.hpp"

KeyboardFilter::KeyboardFilter(QObject *po_parent): QObject{po_parent} {}

/**
 * @brief KeyboardFilter::eventFilter Method called to filter the event, that means in Qt world, every time
 * this filter is installed to a specific QObject object, each time a key is pressed that represents a digit
 * any event will be handled furthermore than this filter, because once the filter is correctly handled
 * it won't be passed elsewhere because of the return true called.
 */
bool KeyboardFilter::eventFilter(QObject *po_watched, QEvent *po_event) {
    if (po_event->type() == QEvent::KeyPress) {
        QKeyEvent *po_keyEvent = static_cast<QKeyEvent *>(po_event);
        QString o_number = "0123456789";

        if (o_number.indexOf(po_keyEvent->text()) != -1) {
            qDebug() << "KeyboardFilter: Number filtered out.";
            return true; // Event correctly handled, no need to propagate into destination object.
            // return false; // Event will be passed at the destination for other event handling !
        }
    }
    return QObject::eventFilter(po_watched, po_event);
}
