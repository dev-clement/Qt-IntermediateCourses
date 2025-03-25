#include <QDebug>
#include <QKeyEvent>
#include "childlineedit.hpp"

ChildLineEdit::ChildLineEdit(QWidget *po_parent): ParentLineEdit{po_parent} {}

void ChildLineEdit::keyPressEvent(QKeyEvent *po_event) {
    qDebug() << "ChildLineEdit: keyPressEvent called !!";
    qDebug() << "ChildLineEdit: is event accepted ? " << po_event->isAccepted();

    // If you decide to ignore the event here, the parent won't have the accept
    // of the event to true
    po_event->ignore();

    // Calling the parent of the event will let the class
    // to forward the calls coming from the user to the
    // class, this way the parent's implementation won't be
    // forgotten.
    // ParentLineEdit::keyPressEvent(po_event);
    if (po_event->key() == Qt::Key_Delete) {
        // In that case, we will handle the Key_Delete ourselves, this won't call the
        // parent implementation of the class in that case.
        qDebug() << "Pressed the delete key";
        clear();
    } else {
        ParentLineEdit::keyPressEvent(po_event);
    }
}
