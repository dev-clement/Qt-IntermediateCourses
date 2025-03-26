#ifndef COLORPICKER_HPP
#define COLORPICKER_HPP

#include <QMap>
#include <QList>
#include <QColor>
#include <QLabel>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class ColorPicker : public QWidget
{
    Q_OBJECT
    struct s_colorMetadata {
        QString o_name;
        QColor e_color;
        int i_col;
        int i_row;
    };
    typedef s_colorMetadata t_colorMetadata;
public:
    explicit ColorPicker(QWidget *po_parent = nullptr);

    QColor color() const;
    void setColor(QColor o_color);

signals:
    void _sig_colorChanged(QColor o_color);

private:
    void initColors();
    void initUi();
    QPushButton *setupButton(const QString &o_text, const QString &o_css, QSizePolicy e_sizePolicy, QWidget *po_parent = nullptr);

private slots:
    void _slot_buttonClicked(const QString &o_color);

private:
    QColor _o_color;
    QList<t_colorMetadata> _o_colorList;
    QGridLayout *_po_gridLayout;
    QLabel *_po_label;
};

#endif // COLORPICKER_HPP
