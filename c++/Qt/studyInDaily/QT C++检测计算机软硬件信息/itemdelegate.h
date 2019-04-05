#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>

class ItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ItemDelegate(QObject *parent=0);

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // ITEMDELEGATE_H
