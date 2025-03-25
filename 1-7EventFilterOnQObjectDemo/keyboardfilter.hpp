#ifndef KEYBOARDFILTER_HPP
#define KEYBOARDFILTER_HPP

#include <QObject>

class KeyboardFilter : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardFilter(QObject *parent = nullptr);

    // QObject interface
    bool eventFilter(QObject *po_watched, QEvent *po_event);

signals:
};

#endif // KEYBOARDFILTER_HPP
