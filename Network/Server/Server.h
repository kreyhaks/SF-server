#pragma once


#include <QSharedPointer>

namespace Network
{

    class Connection;

    class Server
        : public QObject
    {
        Q_OBJECT

        friend class QSharedPointer<Server>;

    signals:
        void newConnection();

    public:
        explicit Server(QObject *parent = nullptr);
        ~Server() = default;

        bool listen(const QHostAddress& address, quint16 port);
        Connection *nextPendingConnection();

    private slots:
        void onNewConnection();
        void onConnectionDestroyed();

    private:
        Connection *createConnection(QTcpSocket *socket);

        QTcpServer _listener;
        QList<Connection *> _freeConnections;
        QMutex _locker;
    };

    typedef QSharedPointer<Server> ServerShp;

}
