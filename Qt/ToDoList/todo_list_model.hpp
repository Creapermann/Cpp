#include "todo_list.hpp"
#include <QAbstractListModel>
#include <QQmlEngine>
#include <memory>

#pragma once


class ToDoListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(ToDoList* list READ list WRITE setList NOTIFY listChanged)
    
public:    
    enum class Roles
    {
        DoneRole = Qt::UserRole,
        DescriptionRole
    };
    
    explicit ToDoListModel(QObject* parent = nullptr);
    
    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QHash<int, QByteArray> roleNames() const override;
    
    void setList(ToDoList* newList);
    ToDoList* list();
    
signals:
    void listChanged();
    
private:
    ToDoList* m_todoList;
};