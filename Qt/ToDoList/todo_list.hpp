#pragma once

#include <QObject>


struct ToDoListItem
{
    QString description;
    bool done;
};


class ToDoList : public QObject
{
    Q_OBJECT
    
public:
    explicit ToDoList(QObject *parent = nullptr);
    const QList<ToDoListItem>& items() const;
    void append(const ToDoListItem& item);
    bool insert(int index, ToDoListItem&& item);
    
private:
    QList<ToDoListItem> m_list;
};