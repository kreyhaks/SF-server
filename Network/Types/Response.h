#pragma once

#include <QSharedPointer>


namespace Network
{
    class Response
    {
        friend class QSharedPointer;

    private:
        Response();
    };

    typedef QSharedPointer<Response> ResopnseShp;
}
