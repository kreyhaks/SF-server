#include "Common.h"
#include "CloseHandler.h"

#ifdef Q_OS_WIN
#include <windows.h>
#endif


namespace
{
    // Should be implemented for each platform
    void platform_install();
    void platform_uninstall();
}


namespace
{

#ifdef Q_OS_WIN

    BOOL WINAPI ConsoleHandler(DWORD type)
    {
        auto& handler = core::CloseHandler::instance();

        switch (type)
        {
        case CTRL_C_EVENT:
        case CTRL_BREAK_EVENT:
        case CTRL_CLOSE_EVENT:
        case CTRL_LOGOFF_EVENT:
        case CTRL_SHUTDOWN_EVENT:
            emit handler.closeRequest();
            return TRUE;

        default:
            break;
        }

        return FALSE;
    }

    void platform_install()
    {
        const auto result = ::SetConsoleCtrlHandler(ConsoleHandler, TRUE);
        Q_ASSERT( result != 0 );
    }

    void platform_uninstall()
    {
        const auto result = ::SetConsoleCtrlHandler(ConsoleHandler, FALSE);
        Q_ASSERT(result != 0);
    }

#else

    void platform_install()
    {
    }

    void platform_uninstall()
    {
    }

#endif

}



namespace core
{

    CloseHandler::CloseHandler( QObject* parent )
        : QObject( parent )
    {
    }

    void CloseHandler::install()
    {
        platform_install();
    }

    void CloseHandler::uninstall()
    {
        platform_uninstall();
    }

}
