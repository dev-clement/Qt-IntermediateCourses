#ifndef WIDGET_HPP
#define WIDGET_HPP

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
    Widget(QWidget *parent = nullptr);
    ~Widget() override;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *po_event) override;
    void mouseReleaseEvent(QMouseEvent *po_event) override;
    void mouseMoveEvent(QMouseEvent *po_event) override;
    void closeEvent(QCloseEvent *po_event) override;
    void contextMenuEvent(QContextMenuEvent *po_event) override;
    void enterEvent(QEnterEvent *po_event) override;
    void leaveEvent(QEvent *po_event) override;
    void keyPressEvent(QKeyEvent *po_event) override;
    void wheelEvent(QWheelEvent *po_event) override;
    void paintEvent(QPaintEvent *po_event) override;
    void resizeEvent(QResizeEvent *po_event) override;

private:
    Ui::Widget *_m_ui;
};
#endif // WIDGET_HPP
