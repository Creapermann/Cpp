#include <QCoreApplication>
#include <QDebug>
#include <QtDebug>
#include <QVariant>
#include <QFile>
#include <QDateTime>


#include <iostream>
#include <memory>
#include <array>


void my_message_output(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    try
    {

        QString filepath{ "debug_log.txt" };
        QFile file(filepath);

        if(!file.open(QFile::Append))
        {
            qInfo() << "Could not open debug-log file!";
            return;
        }

        // Append date-time to output
        QDateTime dt;
        QString message = dt.currentDateTime().toString() + ": " + msg + "  - in file: " + context.file
                + " function: " + context.function + " line: " + QString::number(context.line) + "\n";

        file.write(message.toLocal8Bit());

        file.close();

    }
    catch(std::exception& e) { std::cout << e.what() << "\n"; }
    catch(...) { std::cout << "An error occured!\n"; }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {

        qInstallMessageHandler(my_message_output);

        qDebug() << "test";

    }
    catch(std::exception& e) { std::cout << e.what() << "\n"; }
    catch(...)               { std::cout << "An error occured!\n"; }

    return a.exec();
}
