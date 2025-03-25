#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>
#include "keyboardfilter.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void installingFilters(QObject *po_object);
    void removeFilters(QObject *po_object);

private:
    Ui::Widget      *_po_ui;
    KeyboardFilter  *_po_keyboardFilter;
};
#endif // WIDGET_HPP
