#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringListModel>
#include <todolistpage.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QString DATA_PATH="/home/tinstins/QT_Demo/.ini/text";
    ToDoListPage toDoListPage(nullptr,DATA_PATH);
    QStringListModel *item = toDoListPage.model();

    engine.rootContext()->setContextProperty(QStringLiteral("stringListModel"), item);
    engine.rootContext()->setContextProperty(QStringLiteral("toDoListPage"), &toDoListPage);



    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QT_Demo", "Main");


    return app.exec();
}
