#ifndef CHATROOM_SERVER_H
#define CHATROOM_SERVER_H

#include <string>
#include <stdlib.h>
#include <netinet/in.h>
#include <list>
#include <mysql++.h>
#include "Common.h"

using namespace std;
class Server{
public:
    Server();
    void init();
    void close();
    void start();
private:
    int sendBroadcastMessage(int clientfd, mysqlpp::Connection conn);
    sockaddr_in serverAddr;
    int listener;
    int epfd;
    list<int> clients_list;
};
#endif  //CHATROOM_SERVER_H
