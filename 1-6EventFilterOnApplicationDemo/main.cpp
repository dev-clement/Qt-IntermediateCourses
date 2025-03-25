#include "widget.hpp"
#include "filter.hpp"
#include <QApplication>

int main(int i_argc, char *p_argv[])
{
    QApplication o_a(i_argc, p_argv);
    Widget o_w;

    Filter *po_filter = new Filter(&o_w);

    o_a.installEventFilter(po_filter);

    o_w.show();
    return o_a.exec();
}
