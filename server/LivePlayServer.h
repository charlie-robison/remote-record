//
// Created by Charlie Robison on 2/5/24.
//

#ifndef SERVER_LIVEPLAYSERVER_H
#define SERVER_LIVEPLAYSERVER_H

#include <iostream>
#include <string>
#include "boost/asio.hpp"

using boost::asio::ip::udp;
using boost::asio::ip::address;

/** Provides the methods and properties for the live playing server. */
class LivePlayServer {
private:
    int sendSoundData(udp::socket *, std::string);
public:
    int runServer();
};


#endif //SERVER_LIVEPLAYSERVER_H
