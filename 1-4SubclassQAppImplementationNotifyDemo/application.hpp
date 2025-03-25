#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>

class Application : public QApplication
{
    Q_OBJECT
public:
    explicit Application(int argc, char **argv);

    // QCoreApplication interface
public:
    bool notify(QObject *po_obj, QEvent *po_event);

signals:
};

#endif // APPLICATION_HPP
