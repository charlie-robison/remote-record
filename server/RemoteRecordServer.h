//
// Created by Charlie Robison on 2/7/24.
//

#ifndef SERVER_REMOTERECORDSERVER_H
#define SERVER_REMOTERECORDSERVER_H

#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class RemoteRecordServer {
private:
    int portNum;
    std::string message;

    int sendAudio(tcp::socket *);
    int connectToClient(boost::asio::io_context * io_context, tcp::acceptor * acceptor);
public:
    RemoteRecordServer(int);
    void startServer();
};


#endif //SERVER_REMOTERECORDSERVER_H
