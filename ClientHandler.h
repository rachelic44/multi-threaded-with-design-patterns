//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_CLIENTHANDLER_H
#define PROJECTPART2_CLIENTHANDLER_H

#include "PosixSocket.h"
#include <mutex>
using namespace posix_sockets;

class ClientHandler {
public:
    virtual void handleClient(TCP_client client,mutex * mutex1) = 0 ;
};

#endif //PROJECTPART2_CLIENTHANDLER_Hmain
