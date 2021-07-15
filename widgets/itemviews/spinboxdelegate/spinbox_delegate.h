#ifndef spinbox_delegate_h
#define spinbox_delegate_h

#include <QtWidgets/QStyledItemDelegate>

class SpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    SpinBoxDelegate(QObject *obj = Q_NULLPTR);

    virtual ~SpinBoxDelegate();

    // 创建编辑器
    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    // 设置编辑器数据
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    // 将编辑器中的内容设置到模型中
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    // 设置模型显示位置
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // spinbox_delegate_h