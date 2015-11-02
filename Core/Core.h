#pragma once


namespace net
{
    class Server;
}


namespace core
{

//    class UserManager;
//    class Balancer;
//    class ThreadPool;
//    class DBManager;
//    class Processor;
//    class FileStorage;
//    class IncomingDataHandler;
//    class WebRequestManager;


    class Core
        : public QObject
    {
        Q_OBJECT

    public:
        Core();
        ~Core();

        void init();
        void dispose();
        bool isInitialized() const;

    public slots:
        void close();

    private:
        QSharedPointer<net::Server> _server;
//        QSharedPointer< UserManager > _userManager;
//        QSharedPointer< Balancer > _balancer;
//        QSharedPointer< ThreadPool > _threadPool;
//        QSharedPointer< DBManager > _dbManager;
//        QSharedPointer< Processor > _processor;
//        QSharedPointer< FileStorage > _fileStorage;
//        QSharedPointer< WebRequestManager > _webManager;
//        QSharedPointer< IncomingDataHandler > _incomingDataHandler;

    private:
        bool _isInitialized;
    };

}
