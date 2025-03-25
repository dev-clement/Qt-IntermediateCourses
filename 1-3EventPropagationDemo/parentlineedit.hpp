#ifndef PARENTLINEEDIT_HPP
#define PARENTLINEEDIT_HPP

#include <QLineEdit>

class ParentLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit ParentLineEdit(QWidget *po_parent = nullptr);

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *po_event);

signals:
};

#endif // PARENTLINEEDIT_HPP
