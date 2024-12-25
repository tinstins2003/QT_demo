#include "todolistpage.h"



ToDoListPage::ToDoListPage(QObject *parent,QString filePath) : QObject(parent){
    dataPath = filePath;
    loadData(dataPath);
}

void ToDoListPage::loadData(QString dataPath)
{
    QFile file(dataPath);
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QStringList data;
        while (!in.atEnd()) {
            data.append(in.readLine());
        }
        file.close();
        listItem->setStringList(data);
    }
}

void ToDoListPage::saveData()
{
    QFile file(dataPath);
    if (file.exists() && file.open(QIODevice::WriteOnly  | QIODevice::Text)) {
        QTextStream out(&file);
        QStringList data;
        for (int i = 0; i < listItem->rowCount(); ++i) {
            out << listItem->data(listItem->index(i)).toString() << "\n";
        }
        file.close();

    }
}



void ToDoListPage::addClicked(QString content){
    int newRow = listItem->rowCount();
    listItem->insertRow(newRow);
    QModelIndex index = listItem->index(newRow, 0);
    listItem->setData(index, content);

    saveData();
}

void ToDoListPage::deleteClicked(int index){
    listItem->removeRows(index,1);
    saveData();
}

void ToDoListPage::editClicked(int index, QString newContent)
{
    if (index < listItem->rowCount()) {
        listItem->setData(listItem->index(index), newContent);
        saveData();
    }
}
