#pragma once

#include <QObject>


namespace net
{

    class RequestsManager : public QObject
    {
        Q_OBJECT

        RequestsManager(QObject *parent = nullptr);
        ~RequestsManager() = default;

        void Exec(const RequestShp request);
    };

}
