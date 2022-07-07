#include "todo_list_model.hpp"
#include "qnamespace.h"
#include "qvariant.h"
#include "todo_list.hpp"


ToDoListModel::ToDoListModel(QObject* parent)
{
    
}

int ToDoListModel::rowCount(const QModelIndex& parent) const
{
    if(parent.isValid() || !m_todoList)
        return 0;
    
    return m_todoList->items().count();
}

QVariant ToDoListModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid() || !m_todoList)
        return QVariant();
    
    ToDoListItem data = m_todoList->items().at(index.row());
    switch (role)
    {
    case static_cast<int>(Roles::DescriptionRole):
        return data.description;
        break;
    case static_cast<int>(Roles::DoneRole):
        return data.done;
        break;
    default:
        return QVariant();
    }
}

bool ToDoListModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(!index.isValid())
        return false;

    ToDoListItem data = m_todoList->items().at(index.row());
    switch (role)
    {
    case static_cast<int>(Roles::DescriptionRole):
        data.description = value.toString();
        break;
    case static_cast<int>(Roles::DoneRole):
        data.done = value.toBool();
        break;
    default:
        break;
    }
    
    if(m_todoList->insert(index.row(), std::move(data)))
    {
        emit dataChanged(index, index, QList<int>() << role);
        return true;
    }
    
    return false;
}

Qt::ItemFlags ToDoListModel::flags(const QModelIndex& index) const
{
    if(!index.isValid() || !m_todoList)
        return Qt::NoItemFlags;
    
    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> ToDoListModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames[static_cast<int>(Roles::DoneRole)] = "done";
    roleNames[static_cast<int>(Roles::DescriptionRole)] = "description";
    
    return roleNames;
}

void ToDoListModel::setList(ToDoList* newList)
{
    m_todoList = newList;
    
    emit listChanged();
}

ToDoList* ToDoListModel::list()
{
    if(!m_todoList)
        return nullptr;
    
    return m_todoList;
}