#include <QDebug>
#include "widget.hpp"
#include "application.hpp"

Application::Application(int argc, char **argv): QApplication{argc, argv} {}

bool Application::notify(QObject *po_obj, QEvent *po_event) {
    // Here we are just checking whether or not the type of event
    // is either QMouseButtonPress or QMouseButtonDblClick, meaning
    // that the other type of event will then go to the notify
    // bellow
    if (po_event->type() == QEvent::MouseButtonPress ||
        po_event->type() == QEvent::MouseButtonDblClick) {
        qDebug() << "Application: Mouse pressed or double click detected !!!";

        qDebug() << "Application: " << po_obj->metaObject()->className();

        Widget *po_widget = dynamic_cast<Widget *>(po_obj);
        if (po_widget) {
            qDebug() << "Cast successful !";
        } else {
            qDebug() << "Cast unsuccessful !!";
        }

        return false;
    }

    // Important and clear that calling the parent
    // implementation is very very important for
    // this method in order to forward the event
    return QApplication::notify(po_obj, po_event);
    // return true;
}
