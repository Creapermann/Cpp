#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <iostream>

#include <QObject>
#include <QFile>


class Compressor : public QObject
{
    Q_OBJECT
public:
    explicit Compressor(QObject *parent = nullptr);

    bool compress(const QString& uncompressed_filepath, const QString& compressed_filepath, int compression_level);
    bool decompress(const QString& compressed_filepath, const QString& decompressed_filepath);

private:
    const QString m_head{ "@!!#-#!!@" };
    const int m_block_size = 1024;
    
};

#endif // COMPRESSOR_H
