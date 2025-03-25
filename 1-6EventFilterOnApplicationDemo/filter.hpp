#ifndef FILTER_HPP
#define FILTER_HPP

#include <QObject>

class Filter : public QObject
{
    Q_OBJECT
public:
    explicit Filter(QObject *po_parent = nullptr);

    // QObject interface
    bool eventFilter(QObject *po_watched, QEvent *po_event);

signals:
};

#endif // FILTER_HPP
