#include <QDebug>
#include "todo_list.hpp"


ToDoList::ToDoList(QObject *parent)
    : QObject{parent}
{
    m_list.append({"Do dishes", true});
    m_list.append({"Make bed", false});
    m_list.append({"Go for a walk", false});
    m_list.append({"Gym", true});
}

const QList<ToDoListItem>& ToDoList::items() const
{
    return m_list;
}

void ToDoList::append(const ToDoListItem& item)
{
    m_list.append(item);
}


bool ToDoList::insert(int index, ToDoListItem&& item)
{
    if(index < 0 || index >= m_list.size())
        return false;
    
    if(m_list[index].done == item.done && m_list[index].description == item.description)
        return false;
    
    
    m_list[index] = item;
    return true;
}