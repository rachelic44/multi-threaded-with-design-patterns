//
// Created by user on 06/01/19.
//

#ifndef PROJECTPART2_MYTESTCLIENTHANDLER_H
#define PROJECTPART2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CasheManager.h"
#include <iostream>
#include "ReverseSolver.h"
#include <strings.h>
#include <unistd.h>
#include <string.h>




class MyTestClientHandler : public ClientHandler {
private:
    Solver<string,string>* solver;
    CasheManager<std::string,std::string>* casheManager;
public:
    MyTestClientHandler(Solver<string,string>* reverseSolver) {
        this->solver=reverseSolver;
    }

    virtual void handleClient(int sockClientNumber) {

        int readBytes;
        char buffer[1024];
        bzero(buffer, 1024);
        cout<<"here1"<<endl;
        readBytes = (int) read(sockClientNumber, buffer, 1023);
        if (readBytes < 0) { /* Check if the read succeeded. */
            throw "Could not read from client."; /* If failed throw. */
        }
        cout<<"here2"<<endl;
        string ans=this->solver->solve(buffer);
        const char * ansAsChar=ans.c_str();

        cout<<ansAsChar<<endl;
        long int n=write(sockClientNumber, ansAsChar, strlen(ansAsChar));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        int a=3;
    }

};


#endif //PROJECTPART2_MYTESTCLIENTHANDLER_H
