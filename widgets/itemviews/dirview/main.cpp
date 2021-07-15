#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QListView>
#include <QtWidgets/QFileSystemModel>
#include <QtCore/QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFileSystemModel model;
    model.setRootPath(QDir::currentPath());

    QTreeView tree;
    tree.setModel(&model);
    const QSize availableSize = QApplication::desktop()->availableGeometry(&tree).size();
    tree.resize(availableSize / 2);
    tree.setColumnWidth(0, tree.width() / 3);
    tree.setAnimated(true);
    tree.show();

    return app.exec();
}