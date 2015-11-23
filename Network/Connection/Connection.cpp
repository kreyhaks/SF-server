#include "Common.h"
#include "Connection.h"


using namespace Network;

Connection::Connection(QTcpSocket *socket)
    : QObject(nullptr)
    , _socket(socket)
    , _id(socket != nullptr ? socket->socketDescriptor() : 0)
{
    Q_ASSERT(socket != nullptr);
    socket->setParent(nullptr);

    connect(_socket.data(), &QAbstractSocket::disconnected, this, &Connection::disconnected);
    connect(_socket.data(), &QIODevice::readyRead, this, &Connection::readyRead);
}

Connection::~Connection()
{
}

qintptr Connection::id() const
{
    return _id;
}

QIODevice* Connection::device() const
{
    return _socket.data();
}

void Connection::write(const QByteArray& packet) const
{
    auto bytesWritten = _socket->write(packet);
    if (bytesWritten == -1)
    {
        ;
        // todo: error
    }
}

void Connection::close()
{
    _socket->close();
}
