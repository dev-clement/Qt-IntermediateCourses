#include <QKeyEvent>
#include "parentlineedit.hpp"

ParentLineEdit::ParentLineEdit(QWidget *po_parent): QLineEdit{po_parent} {

}

void ParentLineEdit::keyPressEvent(QKeyEvent *po_event) {
    // (void)po_event;
    qDebug() << "ParentLineEdit: keyPressEvent !";
    qDebug() << "ParentLineEdit: is event accepted ? " << po_event->isAccepted();
    // Not calling the parent of the event will not let the
    // default object to work correctly !
    QLineEdit::keyPressEvent(po_event);
}
