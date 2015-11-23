#pragma once


namespace Network
{

    class Connection
        : public QObject
    {
        Q_OBJECT

    signals:
        void disconnected();
        void readyRead();

    public:
        explicit Connection(QTcpSocket *socket);
        ~Connection();

        qintptr id() const;
        QIODevice *device() const;
        void write(const QByteArray& packet) const;
        void close();

    private:
        QSharedPointer<QTcpSocket> _socket;
        const qintptr _id;
    };

}
