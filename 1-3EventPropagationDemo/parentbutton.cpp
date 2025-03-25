#include <QDebug>
#include <QMouseEvent>
#include "parentbutton.hpp"

ParentButton::ParentButton(QWidget *po_parent): QPushButton{po_parent} {}

void ParentButton::mousePressEvent(QMouseEvent *po_event){
    qDebug() << "ParentButton: mousePressEvent called ! " << po_event->pos();
    // We call the parent method of the mousePressEvent for the
    // application acting normally once the mouse is pressed.
    // QPushButton::mousePressEvent(po_event);
}
