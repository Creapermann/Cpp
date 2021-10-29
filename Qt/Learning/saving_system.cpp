#include <QCoreApplication>
#include <QDebug>
#include <QVariant>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QSettings>

#include <iostream>
#include <memory>
#include <array>


void set_settings(QSettings& settings, const QString& key, const QVariant& value, const QString& group = "")
{
    try{

        if(!group.isEmpty())
            settings.beginGroup(group);

        settings.setValue(key, value);
        settings.sync();

        if(settings.status() != QSettings::NoError)
            std::cout << "An error occured while saving.\n";

        if(!group.isEmpty())
            settings.endGroup();

    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";

        if(!group.isEmpty())
            settings.endGroup();
    }
    catch(...)
    {
        std::cout << "An error occured while saving.\n";

        if(!group.isEmpty())
            settings.endGroup();
    }
}


QVariant get_settings(QSettings& settings, const QString& key, const QString& group = "")
{
    try
    {

        if(!group.isEmpty())
            settings.beginGroup(group);

        auto result = settings.value(key, QVariant::fromValue(nullptr));

        if(!group.isEmpty())
            settings.endGroup();

        return result;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";

        if(!group.isEmpty())
            settings.endGroup();

        return QVariant::fromValue(nullptr);
    }
    catch(...)
    {
        std::cout << "Something went wrong while fatching saved data.\n";

        if(!group.isEmpty())
            settings.endGroup();

        return QVariant::fromValue(nullptr);
    }

    return QVariant::fromValue(nullptr);
}




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const QString filename = a.applicationDirPath() + "/app_settings.ini";
    std::cout << "filename: " << filename.toStdString() << "\n";
    QSettings app_settings(filename, QSettings::Format::IniFormat);

    // Save own company infos
    set_settings(app_settings, QString("Company_Name"), QVariant(QString("Thegs")));
    set_settings(app_settings, QString("Application_Name"), QVariant(QString("Test_App")));
    set_settings(app_settings, QString("Company_Domain"), QVariant(QString("Thegs.com")));

    // Save other company infos
    set_settings(app_settings, QString("Company_Name"), QVariant(QString("Riddon")), QString("Partner_Company"));
    set_settings(app_settings, QString("Application_Name"), QVariant(QString("Other_App")), QString("Partner_Company"));
    set_settings(app_settings, QString("Company_Domain"), QVariant(QString("Riddon.org")), QString("Partner_Company"));


    // Print own company infos
    std::cout << "Company name: " << get_settings(app_settings, QString("Company_Name")).toString().toStdString() << "\n";
    std::cout << "App name: " << get_settings(app_settings, QString("Application_Name")).toString().toStdString() << "\n";
    std::cout << "Domain: " << get_settings(app_settings, QString("Company_Domain")).toString().toStdString() << "\n";

    std::cout << "\n\n";

    // Print other company infos
    std::cout << "Company name: " << get_settings(app_settings, QString("Company_Name"),
                                                  QString("Partner_Company")).toString().toStdString() << "\n";

    std::cout << "App name: " << get_settings(app_settings, QString("Application_Name"),
                                                  QString("Partner_Company")).toString().toStdString() << "\n";

    std::cout << "Domain: " << get_settings(app_settings, QString("Company_Domain"),
                                                  QString("Partner_Company")).toString().toStdString() << "\n";


    return a.exec();
}
