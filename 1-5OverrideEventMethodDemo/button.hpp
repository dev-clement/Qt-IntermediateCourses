#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *po_parent = nullptr);

    // QObject interface
    bool event(QEvent *po_event);

signals:
};

#endif // BUTTON_HPP
