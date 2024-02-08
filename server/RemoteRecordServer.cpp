//
// Created by Charlie Robison on 2/7/24.
//

#include "RemoteRecordServer.h"

/**
 * Connects to a client via TCP.
 * @param io_context - core I/O functionality.
 * @param acceptor - TCP acceptor object to accept clients.
 * @return 0 if there is a successful connection and -1 otherwise.
 */
int RemoteRecordServer::connectToClient(boost::asio::io_context *io_context, tcp::acceptor *acceptor) {
    std::string sender, user, message;
    boost::asio::streambuf receive_buffer;

    try {
        // Creates a new socket for the client.
        tcp::socket socket(*io_context);

        // Accepts the client socket.
        (*acceptor).accept(socket);
        std::cout << "Connected to client." << std::endl;

        // Closes socket connection with client (TCP teardown).
        (socket).close();
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
