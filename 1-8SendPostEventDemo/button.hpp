#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *po_parent = nullptr);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *po_event);
    void mouseReleaseEvent(QMouseEvent *po_event);
    void mouseMoveEvent(QMouseEvent *po_event);

signals:
};

#endif // BUTTON_HPP
