#pragma once

#include "Types/Request.h"

namespace Network
{
    class RequestsManager
    {
    public:
        RequestsManager();

        void SignIn();
        void Execute(RequestShp request);
    };
}
