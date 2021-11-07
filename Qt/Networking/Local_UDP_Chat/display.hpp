#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>

#include <QObject>
#include <QTextStream>


class Display : public QObject
{
    Q_OBJECT
public:
    explicit Display(QObject *parent = nullptr);

    void monitor();
    
signals:
    void send(QString& message, bool prepend_name);
    
public slots:
    void print(const QString& message);

    
private:
    QTextStream m_input_stream;   
};

#endif // DISPLAY_HPP
