#include "compressor.h"

Compressor::Compressor(QObject *parent)
    : QObject(parent)
{
}

bool Compressor::compress(const QString& uncompressed_filepath, const QString& compressed_filepath, int compression_level)
{
    QFile old_file {uncompressed_filepath};
    QFile new_file {compressed_filepath};
    
    try 
    {
        
        // Check if files can be opened
        if(!old_file.open(QFile::ReadOnly)) 
            return false;
        if(!new_file.open(QFile::WriteOnly)) 
            return false;
        
        QByteArray buffer;
        
        while(!old_file.atEnd())
        {
            buffer.append(m_head.toUtf8());
            buffer.append(qCompress(old_file.read(m_block_size), compression_level));
        }
        
        new_file.write(buffer);
        
        new_file.close();
        old_file.close();
        
    }  
    catch (std::exception& e) 
    { 
        std::cout << "\n" << e.what() << "\n";
        new_file.close();
        old_file.close();
    }
    catch (...) 
    { 
        std::cout << "\n an error occured! \n"; 
        new_file.close();
        old_file.close();
    }
}

bool Compressor::decompress(const QString& compressed_filepath, const QString& decompressed_filepath)
{
    QFile compressed_file{compressed_filepath};
    QFile decompressed_file{decompressed_filepath};
    
    try
    {
        
        // Check if files can be opened
        if(!compressed_file.open(QFile::ReadOnly))
            return false;
        if(!decompressed_file.open(QFile::WriteOnly))
            return false;
        
        {
            // Check if file is of right type (compare header)
            QByteArray temp = compressed_file.peek(m_head.toUtf8().size());
            if(temp != m_head.toUtf8())
                return false;
        }
        
        QByteArray buffer;
        
        while(!compressed_file.atEnd())
        {
            compressed_file.read(m_head.toUtf8().size());
            
            auto temp_buffer = compressed_file.peek(m_block_size);
            qint64 header_index = temp_buffer.indexOf(m_head.toUtf8());
            
            if(header_index > -1)
            {
                qint64 bytes_to_read = header_index;
                buffer.append(qUncompress(compressed_file.read(bytes_to_read)));
            }
            else
            {
                buffer.append(qUncompress(compressed_file.readAll()));
            }
        }
        
        decompressed_file.write(buffer);
        
        compressed_file.close();
        decompressed_file.close();
    }
    catch(std::exception& e)
    {
        std::cout << "\n" << e.what() << "\n";        
        compressed_file.close();
        decompressed_file.close();
    }
    catch(...)
    {
        std::cout << "\n an error occured! \n";        
        compressed_file.close();
        decompressed_file.close();
    }
}
