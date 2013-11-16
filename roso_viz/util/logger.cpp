#include "logger.h"
#include <QTime>

Logger* global_logger_instance = NULL;

Logger::Logger(QObject *parent) :
    QObject(parent)
{
    verbose_level = 0;
}

void Logger::printLog(QString msg, int level)
{
    if(level <= verbose_level)
    {
        qDebug(QString(QTime::currentTime().toString("[hh:mm:ss.z]") +msg ).toAscii());
    }
}

Logger* Logger::singleton()
{
    if(!global_logger_instance)
    {
        global_logger_instance = new Logger();
    }
    return global_logger_instance;
}

