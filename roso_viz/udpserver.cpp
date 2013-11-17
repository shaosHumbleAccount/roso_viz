#include "udpserver.h"
#include "util/logger.h"
#include "Setting/settingcenter.h"

UdpServer::UdpServer(QObject *parent) :
    QObject(parent)
{
    udpSocket = new QUdpSocket();
    udpSocket->bind(QHostAddress::Any, SettingCenter::singleton()->getSettingValue("network/port").toInt());

    Logger::singleton()->printLog(QString("UdpServer is listening port %1").arg(SettingCenter::singleton()->getSettingValue("network/port").toInt()));

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

