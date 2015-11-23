#pragma once

#include <QSharedPointer>
#include <QByteArray>


namespace Network
{
    class Request
    {
        friend class QSharedPointer;

    private:
        Request();

    public:
        QByteArray& requestData();

    private:
        QByteArray _data;
    };

    typedef QSharedPointer<Request> RequestShp;
}
