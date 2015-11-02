#include "Common.h"
#include "Core.h"

#include "Network/Server/Server.h"

//#include "Utils/Waiter/Waiter.h"

//#include "Commands/CommandFactory.h"
//#include "Users/UserManager.h"
//#include "Processing/Balancer.h"
//#include "Processing/ThreadPool.h"
//#include "Processing/Processor.h"
//#include "Processing/IncomingDataHandler.h"
//#include "DataBase/DBManager.h"
//#include "FileStorage/FileStorage.h"
//#include "Log/LogManager.h"
//#include "DataExchange/WebExchange/WebRequestManager.h"

//#include "Translator.h"
#include "Core/Settings.h"
#include "CloseHandler.h"


namespace core
{

    Core::Core()
        : _isInitialized(false)
    {
        // Direct initialization order
        _server = QSharedPointer<net::Server>::create();
//        _threadPool = QSharedPointer< ThreadPool >::create( 0 );
//        _balancer = QSharedPointer< Balancer >::create( _threadPool );
//        _dbManager = QSharedPointer< DBManager >::create();
//        _processor = QSharedPointer< Processor >::create( _balancer );
//        _userManager = QSharedPointer< UserManager >::create();
//        _fileStorage = QSharedPointer< FileStorage >::create();
//        _webManager = QSharedPointer< WebRequestManager >::create();
//        _incomingDataHandler = QSharedPointer< IncomingDataHandler >::create( _userManager, _dbManager, _processor, _fileStorage, _webManager );
    }

    Core::~Core()
    {
    }

    void Core::init()
    {
        Q_ASSERT(!_isInitialized);

        // App settings
        const auto appDir = QCoreApplication::applicationDirPath();
        QDir::setCurrent(appDir);

        QCoreApplication::setApplicationName(PRODUCT_NAME);
        QCoreApplication::setApplicationVersion(PRODUCT_VERSION);

        auto& closeHandler = CloseHandler::instance();
        // connect(&closeHandler, &CloseHandler::closeRequest, this, &Core::close, Qt::DirectConnection);
        closeHandler.install();

        // Commands
//        CommandFactory::instance().registerSignatures();    // Fix for static members initialization order (T::_signature)

        // Threads
//        _threadPool->start();
//        auto threadNetwork = _threadPool->threads().at( ThreadPool::MainThread );
//        auto threadIO = _threadPool->threads().at( ThreadPool::IOThread );
//        auto threadDb = _threadPool->threads().at( ThreadPool::DBThread );
//        Q_ASSERT( threadIO );
//        Q_ASSERT( threadDb );

        // Translation
//        Translator myTranslator;
//        if ( !myTranslator.init() )
//        {
//            qWarning() << "Could not load translation";
//            return;
//        }

        // Balancer
//        _balancer->initWorkers();

        // Logs
//        auto logManager = &LogManager::instance();
//        logManager->moveToThread( threadIO );
//        utils::Waiter::waitOne( logManager, &LogManager::initialized,
//            []() { QTimer::singleShot( 0, &LogManager::instance(), &LogManager::init ); } );
//        const auto loggerInitialized = logManager->isInitialized();
//        if ( !loggerInitialized )
//        {
//            qWarning() << "Could not initialize logger";
//            return;
//        }

        // DB
//        _dbManager->moveToThread( threadDb );
//        utils::Waiter::waitOne( _dbManager.data(), &DBManager::initialized,
//            [this]() { QTimer::singleShot( 0, _dbManager.data(), &DBManager::init ); } );
//        const auto dbInitialized = _dbManager->isInitialized();
//        if ( !dbInitialized )
//        {
//            qWarning() << "Could not initialize database";
//            return;
//        }

        // File storage
//        const auto storageInitialized = _fileStorage->init();
//        if ( !storageInitialized )
//        {
//            qWarning() << "Could not initialize file storage";
//            return;
//        }
//        _fileStorage->moveToThread( threadIO );

        // User manager
//        _userManager->setIncomingDataHandler( _incomingDataHandler );
//        _userManager->watchServer( _server.data() );

        // Network
        Settings settings;
        settings.setDefaultValue("okk_server/Port", 6006);
        quint16 port = settings->value("okk_server/Port").toUInt();

        const auto serverStarted = _server->listen(QHostAddress::Any, port);
        if (!serverStarted)
        {
            qWarning() << "Could not start listening network port: " << port;
            return;
        }

        // Web API
//        settings.setDefaultValue( "api_general/url", QUrl( "http://192.168.211.30:81/api/api_general_taxi_spb.php" ).toDisplayString() );
//        settings.setDefaultValue( "api_general/login", "okk" );
//#ifdef _DEBUG
//        settings.setDefaultValue( "api_general/password", "ufhe_e7bbbewGhed16t" );
//#else
//        settings.setDefaultValue( "api_general/password", "" );
//#endif

//        const auto url = settings->value( "api_general/url" ).toUrl();
//        const auto login = settings->value( "api_general/login" ).toString();
//        const auto password = settings->value( "api_general/password" ).toString();

//        _webManager->setCredentials( login, password );

//        _webManager->moveToThread( threadNetwork );
//        utils::Waiter::waitOne( _webManager.data(), &WebRequestManager::initialized,
//            [this]() { QTimer::singleShot( 0, _webManager.data(), &WebRequestManager::init ); } );
//        const auto webApiStarted = _webManager->isInitialized();
//        if ( !webApiStarted )
//        {
//            qWarning() << "Could not start web API: " << url.toDisplayString();
//            return;
//        }

        // Done
        _isInitialized = true;
    }

    bool Core::isInitialized() const
    {
        return _isInitialized;
    }

    void Core::close()
    {
        // Must be thread-safe
        dispose();
        QCoreApplication::quit();

        // App will be terminated there
    }

    void Core::dispose()
    {
        qDebug() << "Shutdown...";

        //QCoreApplication::instance()->removeNativeEventFilter(_eventFilter.data());
        CloseHandler::instance().uninstall();

//        _incomingDataHandler.reset();
        _server.reset();
//        _userManager.reset();
//        _balancer.reset();
//        _dbManager.reset();
//        _threadPool.reset();

        _isInitialized = false;
    }

}
