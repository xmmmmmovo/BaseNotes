#include <stdio.h> 
/**
 * 假定：
 * childItems: vector --- hashnodes.bookNums
 * 
*/

TreeItem::TreeItem(const QList &data, TreeItem *parent)
{
    parentItem = parent;
    itemData = data;
}

TreeItem::~TreeItem()
{
    qDeleteAll(childItems);
}

void TreeItem::a(TreeItem *item)
{
    childItems.append(item);
}

TreeItem *TreeItem::child(int row)
{
    return childItems.value(row);
}

int TreeItem::childCount() const
{
    return childItems.count();
}

int TreeItem::columnCount() const
{
    return itemData.count();
}

QVariant TreeItem::data(int column) const
{
    return itemData.value(column);
}

TreeItem *TreeItem::parent()
{
    return parentItem;
}

int TreeItem::row() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast(this));

    return 0;
}

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    QList rootData; // 定义根节点
    rootData << "Title";
    rootItem = new TreeItem(rootData);
}
/**
 * 析构函数
*/
TreeModel::~TreeModel()
{
    delete rootItem; // rootItem可以利用vector
}

void TreeModel::setXML(QString xmlFile)
{
    toolList = Util::parse(xmlFile);
    setupModelData(rootItem);
}

/**
 * 计算列数
*/
int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

/**
 * 获取数据函数
*/
QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    TreeItem *item = static_cast(index.internalPointer());

    ToolUtil toolUtil;
    for (int i = 0; i < toolList.count(); ++i)
    {
        toolUtil = toolList.at(i);
        if (toolUtil.id == item->data(0))
        {
            break;
        }
    }

    if (role == Qt::DisplayRole)
    {
        return toolUtil.text;
    }
    else if (role == Qt::DecorationRole)
    {
        return QIcon(Util::exePath() + "\\Resources\\toolicon\\" + toolUtil.toolicon);
    }
    else if (role == Qt::ToolTipRole)
    {
        return toolUtil.tooltip;
    }
    else
    {
        return QVariant();
    }
}

/**
 * 允许选中
*/
Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

/**
 * 头数据
*/
QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

/**
 * 相当于坐标点
*/
QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent)const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

/**
 * 返回父节点
*/
QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast(index.internalPointer());
    TreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

/**
 * 记录行数
*/
int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast(parent.internalPointer());

    return parentItem->childCount();
}

/**
 * 返回节点(可能是itemdata)
*/
TreeItem * TreeModel::item(TreeItem* item, ToolUtil tool)
{
    TreeItem *treeItem = NULL;
    if (item == NULL)
    {
        return treeItem;
    }

    int parentId = tool.parentId;

    if (item->data(0) == parentId)
    {
        treeItem = item;
    }
    else
    {
        for (int j = 0; j < item->childCount(); ++j)
        {
            TreeItem *childItem = item->child(j);
            TreeItem *item2 = this->item(childItem, tool);
            if (item2)
            {
                treeItem = item2;
                break;
            }
        }
    }

    return treeItem;
}

/**
 * 建立model数据
*/
void TreeModel::setupModelData(TreeItem *parent)
{
    QList parents;
    parents << parent;

    for (int i = 0; i < toolList.count(); ++i)
    {
        ToolUtil tool = toolList.at(i);
        QList columnData;
        columnData << tool.id;

        for(int j = 0; j < parents.count(); ++j)
        {

            TreeItem* item = this->item(parents.at(j), tool);
            if (item)
            {
                item->a(new TreeItem(columnData, item));
            }
            else
            {
                parents.last()->a(new TreeItem(columnData, parents.last()));
            }
        }
    }
}