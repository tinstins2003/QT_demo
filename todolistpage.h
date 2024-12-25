#ifndef TODOLISTPAGE_H
#define TODOLISTPAGE_H
#include <QObject>
#include <QDebug>
#include<QQuickItem>
#include <QStringListModel>
#include <QFile>
#include <QNetworkAccessManager>

class ToDoListPage:public QObject
{
    Q_OBJECT

public:
    explicit ToDoListPage(QObject *parent = nullptr);

    QStringListModel *model() const {
        return listItem;
    }
    void loadData();
    void saveData();

signals:

public slots:
    void onReplyFinished();
    void addClicked(QString content);
    void deleteClicked(int index);
    void editClicked(int index, QString newContent);

private:
    QStringListModel *listItem = new QStringListModel();
    QString host = "http://localhost:3000/";
    QNetworkAccessManager httpReq;


};

#endif // TODOLISTPAGE_H
