#include "Request.h"

using namespace Network;

Request::Request()
{
    _data.append("test");
}

QByteArray& Request::requestData()
{
    return _data;
}
