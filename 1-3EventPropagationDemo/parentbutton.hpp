#ifndef PARENTBUTTON_HPP
#define PARENTBUTTON_HPP

#include <QPushButton>

class ParentButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ParentButton(QWidget *po_parent = nullptr);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *po_event);

signals:
};

#endif // PARENTBUTTON_HPP
