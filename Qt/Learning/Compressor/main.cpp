#include <iostream>
#include <memory>
#include <array>

#include <QCoreApplication>
#include <QDebug>
#include <QtDebug>
#include <QVariant>
#include <QFile>
#include <QDir>
#include <QDateTime>

#include "compressor.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {
        
        QFile raw_file {"raw.txt"};
        QFile compressed_file{"compressed.txt"};
        QFile decompressed_file{"decompressed.txt"};
        
        
        compressed_file.open(QFile::ReadWrite);
        
        if(!raw_file.open(QFile::WriteOnly))
        {
            qDebug() << "couldnt open test file";
        }
        
        for(int i{0}; i < 100000; ++i)
        {
            raw_file.write((QString::number(i) + QString("\n")).toUtf8());
        }
        
        
        compressed_file.close();
        raw_file.close();
        
        Compressor comp;
        
        comp.compress(QDir::currentPath() + "/" + raw_file.fileName(), QDir::currentPath() + "/" + compressed_file.fileName(), 9);
        comp.decompress(QDir::currentPath() + "/" + compressed_file.fileName(), QDir::currentPath() + "/" + decompressed_file.fileName());
    }  
    catch (std::exception& e) { std::cout << "\n" << e.what() << "\n"; }
    catch (...) { std::cout << "\n an error occured! \n"; }
    

    return a.exec();
}
