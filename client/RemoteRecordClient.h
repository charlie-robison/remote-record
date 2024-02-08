//
// Created by Charlie Robison on 2/7/24.
//

#ifndef CLIENT_REMOTERECORDCLIENT_H
#define CLIENT_REMOTERECORDCLIENT_H

#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class RemoteRecordClient {
private:
    int portNum;
    void receiveAudio(tcp::socket *);
public:
    RemoteRecordClient(int);
    int connectToServer();
};


#endif //CLIENT_REMOTERECORDCLIENT_H
