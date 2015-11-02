#pragma once

#include "Types/Singleton.h"


namespace core
{

    class CloseHandler
        : public QObject
        , public Singleton<CloseHandler>
    {
        friend class Singleton<CloseHandler>;

        Q_OBJECT

    signals:
        void closeRequest();

    public:
        ~CloseHandler() = default;

        void install();
        void uninstall();

    private:
        explicit CloseHandler(QObject *parent = nullptr);
    };

}
