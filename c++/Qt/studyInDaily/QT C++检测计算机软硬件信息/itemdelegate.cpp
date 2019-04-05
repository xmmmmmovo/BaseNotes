#pragma execution_character_set("utf-8")
#include "itemdelegate.h"
#include <QTextOption>
#include <QPainter>
#include <QtWidgets>
#include <checkdlg.h>

ItemDelegate::ItemDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    if(index.column() == 0)
    {
        int a = 10;
    }
    else if(index.column() == 1)
    {
        int tip = index.data(Qt::UserRole).toInt();
        QString name;
        switch (tip)
        {
            case 0: //等待检测
                name = "";
                break;
            case 1://正在检测
                name = ":/images/checking";
                break;
            case 2://通过
                name = ":/images/pass";
                break;
            case 3://警告
                name = ":/images/warning";
                break;
            case 4://未通过
                name = ":/images/faile";
                break;
            default://不显示
                name = "";
        }

        if(!name.isEmpty())
        {
            QImage image(name);
            int x = option.rect.topLeft().x() ;
            int y = option.rect.topLeft().y() + (option.rect.height() - image.height()) / 2;

             painter->drawImage(x, y, image);
        }
    }
    else if(index.column() == 2)
    {
        int tip = index.data(Qt::UserRole).toInt();
        QString des = index.data(Qt::UserRole+1).toString();
        QColor color;
        switch (tip)
        {
            case 0: //等待检测
                color.setRgb(153, 153, 153);
                break;
            case 1://正在检测
                color.setRgb(255, 255, 255);
                break;
            case 2://通过
                color.setRgb(0, 190, 45);
                break;
            case 3://警告
                color.setRgb(255, 210, 0);
                break;
            case 4://未通过
                color.setRgb(255, 69, 79);
                break;
            default://不显示
                color.setRgb(153, 153, 153);
        }
        painter->setPen(color);
        QTextOption op;
        op.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(12);

        painter->setFont(font);
        QPointF p(option.rect.x(),option.rect.y());
//        painter->drawText(index.data(Qt::DisplayRole).toString(), p);
        QRect rect = option.rect;
        if(des.contains("describe"))
            rect.setLeft(85);
        else
            rect.setLeft(50);
        painter->drawText(rect, index.data(Qt::DisplayRole).toString(), op);

    }
    else
    {
        int tip = index.data(Qt::UserRole).toInt();
        QColor color;
        switch (tip)
        {
            case 0: //等待检测
                color.setRgb(153, 153, 153);
                break;
            case 1://正在检测
                color.setRgb(255, 255, 255);
                break;
            case 2://通过
                color.setRgb(0, 190, 45);
                break;
            case 3://警告
                color.setRgb(255, 210, 0);
                break;
            case 4://未通过
                color.setRgb(255, 69, 79);
                break;
            default://不显示
                color.setRgb(153, 153, 153);
        }
        painter->setPen(color);
        QTextOption op;
        op.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(12);

        painter->setFont(font);
        QPointF p(option.rect.x(),option.rect.y());
//        painter->drawText(index.data(Qt::DisplayRole).toString(), p);
        QRect rect = option.rect;
//        rect.setLeft(20);
        painter->drawText(rect, index.data(Qt::DisplayRole).toString(), op);

    }
}
