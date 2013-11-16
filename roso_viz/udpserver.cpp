#include "udpserver.h"
#include "util/logger.h"

UdpServer::UdpServer(QObject *parent) :
    QObject(parent)
{
    port = 7086;

    udpSocket = new QUdpSocket();
    udpSocket->bind(QHostAddress::Any, port);

    Logger::singleton()->printLog(QString("UdpServer is listening port %1").arg(port));

    bool success = connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
    Q_ASSERT(success);
}


void UdpServer::readPendingDatagrams()
{
    //Logger::singleton()->printLog("readPendingDatagrams");
    while (udpSocket->hasPendingDatagrams()) {
        //Logger::singleton()->printLog("Data recieved");
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);

        QString msg = QString(datagram);
        Logger::singleton()->printLog("Data recieved: " + msg);
        emit messageRecieved(msg);
    }
    //Logger::singleton()->printLog("readPendingDatagrams ends");
}

