#include "Common.h"

//#include "Core/Core.h"
//#include "Log/LogManager.h"


int main(int argc, char *argv[])
{
    QCoreApplication a( argc, argv );

    const auto maincpp_sourceDir = QFileInfo( __FILE__ ).absoluteDir().absolutePath();
    const auto root_sourceDir = QDir( QString( "%1/.." ).arg( maincpp_sourceDir ) );

//    auto& logManager = core::LogManager::instance();
//    logManager.setSourceRootDir( root_sourceDir.absolutePath() );
//    logManager.setModuleName( MODULE_NAME );

//    core::Core core;
//    core.init();

//    if ( !core.isInitialized() )
//    {
//        qWarning() << "Core is not initialized. Terminating...";
//        core.dispose();
//        return 1;
//    }

    qDebug() << "Started...";

//    LOG( utils::log::Trace, core::LogManager::Common, "Server started", QJsonObject() );

    a.exec();

    return 0;
}
