//
// Created by Charlie Robison on 2/7/24.
//

#ifndef CLIENT_LIVEPLAYCLIENT_H
#define CLIENT_LIVEPLAYCLIENT_H

#include <iostream>
#include <string>
#include "boost/asio.hpp"

using boost::asio::ip::udp;

/** Provides the methods and properties for the live playing client. */
class LivePlayClient {
private:
    boost::array<char, 1> receiveSoundData(udp::socket *);
public:
    int connectToServer();
};


#endif //CLIENT_LIVEPLAYCLIENT_H
