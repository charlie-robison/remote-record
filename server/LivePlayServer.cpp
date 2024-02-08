//
// Created by Charlie Robison on 2/5/24.
//

#include "LivePlayServer.h"

int LivePlayServer::sendSoundData(udp::socket * socket, std::string message) {
    int returnVal;
    udp::endpoint remote_endpoint;
    boost::system::error_code ignored_error;

    // Attempts to send a message from the server to the client.
    try {
        // Makes a connection to client.
        remote_endpoint = udp::endpoint(address::from_string("localhost"), 13);

        // Sends message to the client.
        socket->send_to(boost::asio::buffer(message), remote_endpoint, 0, ignored_error);
        std::cout << "Sent message: " << message << " to client" << std::endl;
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

    returnVal = 0;

    // Attempts to create UDP socket listening on port 13.
    try {
        boost::asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 13));
        std::cout << "Server is running on port 13...";

        // Waits for connection.
        for (;;) {
            // Sends sound data.
            sendSoundData(&socket, "Hello World");
        }

    } catch (std::exception& e) {
        returnVal = -1;
    }

    return returnVal;
}