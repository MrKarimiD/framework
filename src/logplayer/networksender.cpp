#include "networksender.h"

NetworkSender::NetworkSender(QObject *parent) :
    QObject(parent)
{
    udpSocket = new QUdpSocket(this);
}

void NetworkSender::configure(QString ip, quint16 port)
{
    groupAddress = QHostAddress(ip);
    udpSocket->setSocketOption(QAbstractSocket::MulticastTtlOption,1);
    this->port = port;
}

void NetworkSender::sendData(QByteArray out)
{
    udpSocket->writeDatagram(out.data(), out.size(),
                                groupAddress, port);
}
