//
// Created by Charlie Robison on 2/7/24.
//

#include "RemoteRecordServer.h"

/**
 * Connects to a client via TCP.
 * @param io_context - Core I/O functionality.
 * @param acceptor - TCP acceptor object to accept clients.
 * @return 0 if there is a successful connection and -1 otherwise.
 */
int RemoteRecordServer::connectToClient(boost::asio::io_context *io_context, tcp::acceptor *acceptor) {
    int returnVal;
    std::string sender, user, message;
    boost::asio::streambuf receive_buffer;

    try {
        // Creates a new socket for the client.
        tcp::socket socket(*io_context);

        // Accepts the client socket.
        (*acceptor).accept(socket);
        std::cout << "Connected to client." << std::endl;
        returnVal = 0;

        // Closes socket connection with client (TCP teardown).
        (socket).close();
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        returnVal = -1;
    }

    return returnVal;
}

/**
 * Starts the TCP Server.
 * @param portNum - The port number the server process will run on.
 */
void RemoteRecordServer::startServer(int portNum) {
    try {
        boost::asio::io_context io_context;

        // Acceptor object used to listen for connections.
        // Listens for ipv4 addresses and on the port number given.
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), portNum));

        std::cout << "Server is running..." << std::endl;
        std::cout << "Accepting client connections..." << std::endl;

        // Waits for client connections.
        for (;;) {
            // Searches for client connection.
            connectToClient(&io_context, &acceptor);
        }
    } catch (std::exception& e){
        std::cout << "Error" << std::endl;
    }
}
