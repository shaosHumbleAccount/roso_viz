#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = 0);
    
    static Logger* singleton();
signals:
    
public slots:
    void printLog(QString msg, int level = 0);

private:
    int verbose_level;
};

#endif // LOGGER_H
