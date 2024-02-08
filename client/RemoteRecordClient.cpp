//
// Created by Charlie Robison on 2/7/24.
//

#include "RemoteRecordClient.h"

/**
 * Creates a connection with the server.
 * @param io_service - Provides I/O functionality.
 * @return 0 if the connection is successful and -1 otherwise.
 */
int RemoteRecordClient::connectToServer(boost::asio::io_service * io_service) {
    int returnVal;

    try {
        // Creates socket for the client.
        tcp::socket socket(*io_service);

        // Connects to server socket.
        socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("localhost"), portNum));
        returnVal = 0;

        // Closes the socket connection with the server.
        socket.close();
    } catch (std::exception& e) {
        std::cout << "Error" << e.what() << std::endl;
        returnVal = -1;
    }

    return returnVal;
}
