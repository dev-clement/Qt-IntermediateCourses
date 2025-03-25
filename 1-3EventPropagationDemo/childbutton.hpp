#ifndef CHILDBUTTON_HPP
#define CHILDBUTTON_HPP

#include "parentbutton.hpp"

class ChildButton : public ParentButton
{
    Q_OBJECT
public:
    explicit ChildButton(QWidget *po_parent = nullptr);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *po_event);

signals:
};

#endif // CHILDBUTTON_HPP
