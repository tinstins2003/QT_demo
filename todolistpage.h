#ifndef TODOLISTPAGE_H
#define TODOLISTPAGE_H
#include <QObject>
#include <QDebug>
#include<QQuickItem>
#include <QStringListModel>
#include <QFile>

class ToDoListPage:public QObject
{
    Q_OBJECT

public:
    explicit ToDoListPage(QObject *parent = nullptr,QString filePath="");

    QStringListModel *model() const {
        return listItem;
    }
    void loadData(QString dataPath);
    void saveData();

signals:

public slots:
    void addClicked(QString content);
    void deleteClicked(int index);
    void editClicked(int index, QString newContent);

private:
    QStringListModel *listItem = new QStringListModel();
    QString dataPath;
};

#endif // TODOLISTPAGE_H
