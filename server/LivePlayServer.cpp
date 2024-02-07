//
// Created by Charlie Robison on 2/5/24.
//

#include "LivePlayServer.h"

int LivePlayServer::sendSoundData(udp::socket socket, std::string message) {
    int returnVal;

    // Attempts to send a message from the server to the client.
    try {
        socket.send(boost::asio::buffer(message));
        returnVal = 0;
    } catch (std::exception& e) {
        returnVal = -1;
    }

    return returnVal;
}

/**
 * Creates a UDP server which listens on port 13.
 * @return 0 if server is successfully running and -1 otherwise.
 */
int LivePlayServer::runServer() {
    int returnVal;

    // Attempts to create UDP socket listening on port 13.
    try {
        boost::asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 13));
        returnVal = 0;
    } catch (std::exception& e) {
        returnVal = -1;
    }

    return returnVal;
}