#include <QtWidgets/QApplication>
#include <QtWidgets/QTableView>
#include <QtGui/QStandardItemModel>

#include "spinbox_delegate.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QStandardItemModel model(4, 2);

    SpinBoxDelegate delegate;

    QTableView view;
    view.setModel(&model);
    view.setItemDelegate(&delegate);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            QModelIndex idx = model.index(i, j);
            model.setData(idx, (i + 1) * (j + 1));
        }
    }

    view.show();

    return app.exec();
}