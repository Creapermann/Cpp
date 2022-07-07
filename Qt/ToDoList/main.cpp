#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "todo_list.hpp"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    
    
    QQmlApplicationEngine engine;
    
    ToDoList toDoList;
    engine.rootContext()->setContextProperty("toDoList", &toDoList);
    
    const QUrl url(u"qrc:/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    
    return app.exec();
}
