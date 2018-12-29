#ifndef TREEMODELCUS_H
#define TREEMODELCUS_H
/**
  自定义树形模型
*/
#include "structs.h"
#include <QTreeView>
#include <QVariant>
class treeModelCus: public QAbstractItemModel // 继承自模板类 纯复现
{
    Q_OBJECT
public:
    treeModelCus(QObject *parent);
private:
};
/**
  构造函数
*/
treeModelCus::treeModelCus(QObject *parent):
    QAbstractItemModel(parent){ // 委托构造函数
    treenode *rootNode = new treenode(); // 分配空间

}

#endif // TREEMODELCUS_H
