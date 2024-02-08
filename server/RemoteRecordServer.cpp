//
// Created by Charlie Robison on 2/7/24.
//

#include "RemoteRecordServer.h"

/**
 * Creates a new RemoteRecordServer instance.
 * @param portNum
 */
RemoteRecordServer::RemoteRecordServer(int portNum) {
    this->portNum = portNum;
}

/**
 * Sends audio from the server to the client via TCP.
 * @param socket - The client socket.
 * @return 0 if the send was successful and -1 otherwise.
 */
int RemoteRecordServer::sendAudio(tcp::socket * socket, std::string message) {
    int returnVal;

    try {
        // Sends the message to the client TCP socket.
        boost::asio::write(*socket, boost::asio::buffer(message));
        returnVal = 0;
    } catch (std::exception& e) {
        std::cout << "Failed to send message: " << e.what() << std::endl;
        returnVal = -1;
    }

    return returnVal;
}

/**
 * Connects to a client via TCP.
 * @param io_context - Core I/O functionality.
 * @param acceptor - TCP acceptor object to accept clients.
 * @return 0 if there is a successful connection and -1 otherwise.
 */
int RemoteRecordServer::connectToClient(boost::asio::io_context *io_context, tcp::acceptor *acceptor) {
    int returnVal;
    std::string message;
    boost::asio::streambuf receive_buffer;

    try {
        // Creates a new socket for the client.
        tcp::socket socket(*io_context);

        // Accepts the client socket.
        (*acceptor).accept(socket);
        std::cout << "Connected to client." << std::endl;
        returnVal = 0;

        message = "Hello From Server.\n";

        // Sends audio to the client.
        if (sendAudio(&socket, message) == 0) {
            std::cout << "Message sent: " << message;
        }

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
void RemoteRecordServer::startServer() {
    try {
        boost::asio::io_context io_context;

        // Acceptor object used to listen for connections.
        // Listens for ipv4 addresses and on the port number given.
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), portNum));

        std::cout << "Server is running on port " << portNum << "..." << std::endl;
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
