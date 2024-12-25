#include "todolistpage.h"

#include <QJsonDocument>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>



ToDoListPage::ToDoListPage(QObject *parent) : QObject(parent){
    loadData();
}

void ToDoListPage::loadData(){
    QNetworkReply *word = httpReq.get(QNetworkRequest(host));
    connect(word, &QNetworkReply::finished, this, &ToDoListPage::onReplyFinished);
}

void ToDoListPage::saveData()
{
    QJsonObject updateData;
    QJsonArray data;
    for(const  auto&value:listItem->stringList()){
        data.append(value);
    }
    updateData["lines"]={data};
    qDebug()<<QJsonDocument(updateData).toJson();
    QNetworkRequest req(host);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *update = httpReq.post(req, QJsonDocument(updateData).toJson());
    connect(update,&QNetworkReply::finished,[update](){
        if (update->error() == QNetworkReply::NoError) {
            qDebug() << "Update success";
        } else {
            qDebug() << "Error: "<<update->error();
        }
        update->deleteLater();
    });
}


void ToDoListPage::onReplyFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError) {

        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonArray todos = jsonDoc.array();
        QStringList data;

        for (const QJsonValue &value : todos) {
            qDebug()<<"Content: "<<value.toString();
            data.append(value.toString());
        }
        listItem->setStringList(data);
    }
    reply->deleteLater();
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
