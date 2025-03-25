#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "button.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *po_parent = nullptr);
    ~Widget();

private:
    Ui::Widget *_po_ui;
    Button *_po_btn;
};
#endif // WIDGET_HPP
