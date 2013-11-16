#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QtNetwork>

class UdpServer: public QObject
{
    Q_OBJECT
public:
    explicit UdpServer(QObject *parent = 0);
    
signals:
    void messageRecieved(QString msg);

private slots:
    void readPendingDatagrams();

private:
    QUdpSocket* udpSocket;
    int port;
};

#endif // UDPSERVER_H
