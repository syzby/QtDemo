#include "spinbox_delegate.h"
#include <QtWidgets/QSpinBox>

SpinBoxDelegate::SpinBoxDelegate(QObject *obj)
    :QStyledItemDelegate(obj)
{

}

SpinBoxDelegate::~SpinBoxDelegate()
{

}

QWidget* SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    auto spinBox = new QSpinBox(parent);
    spinBox->setFrame(false);   // 设置QSpinBox为无边框
    spinBox->setMinimum(0);
    spinBox->setMaximum(100);
    return spinBox;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int val = index.model()->data(index, Qt::EditRole).toInt();
    auto spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(val);
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    auto spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText(); // 保证能读取到最新的值
    model->setData(index, spinBox->value(), Qt::EditRole);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}