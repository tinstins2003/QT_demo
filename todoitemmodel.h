#ifndef TODOITEMMODEL_H
#define TODOITEMMODEL_H

#include "todolistpage.h"

#include <QAbstractListModel>
#include <QObject>


class ToDoItemModel:public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ToDoItemModel(QObject *parent = nullptr);


    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    enum Roles {
        TitleRole = Qt::UserRole + 1,
        DoneRole
    };

    QHash<int, QByteArray> roleNames() const override;

    void addItem(const QString &title, bool done);

private:
    QList<QString> m_items;
};
#endif // TODOITEMMODEL_H
