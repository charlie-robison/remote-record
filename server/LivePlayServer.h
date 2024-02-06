//
// Created by Charlie Robison on 2/5/24.
//

#ifndef SERVER_LIVEPLAYSERVER_H
#define SERVER_LIVEPLAYSERVER_H

#include <string>
#include "boost/asio.hpp"

using boost::asio::ip::udp;

/** Provides the methods and properties for the live playing server. */
class LivePlayServer {
private:
    boost::asio::io_context io_context;
    udp::socket socket;
    int sendSoundData();
public:
    int runServer();
};


#endif //SERVER_LIVEPLAYSERVER_H
