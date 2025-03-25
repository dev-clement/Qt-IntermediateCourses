#ifndef CHILDLINEEDIT_HPP
#define CHILDLINEEDIT_HPP

#include "parentlineedit.hpp"

class ChildLineEdit : public ParentLineEdit
{
    Q_OBJECT
public:
    explicit ChildLineEdit(QWidget *po_parent = nullptr);

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *po_event);

signals:
};

#endif // CHILDLINEEDIT_HPP
