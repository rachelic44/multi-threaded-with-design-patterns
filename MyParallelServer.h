//
// Created by user on 13/01/19.
//

#ifndef PROJECTPART2_MYPARALLELSERVER_H
#define PROJECTPART2_MYPARALLELSERVER_H

#include "Server.h"
#include <iostream>
#include <strings.h>
#include <vector>

using namespace std;
using namespace server_side;


class MyParallelServer : public Server {
private:
    vector<int> clientsVec;
    bool *toStop;
public:
    MyParallelServer() {
        this->toStop= new bool(false);
    }
    virtual void open(int portNumber, ClientHandler* clientHandler);
    virtual void stop(int);
    //  void funcForThread(TCP_server tcp_server,TCP_client tcp_client,ClientHandler* clientHandler);
};

#endif //PROJECTPART2_MYPARALLELSERVER_H