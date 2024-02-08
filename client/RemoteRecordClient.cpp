//
// Created by Charlie Robison on 2/7/24.
//

#include "RemoteRecordClient.h"

/**
 * Creates a new RemoteRecordClient.
 * @param portNum - The port number the server process is running on.
 */
RemoteRecordClient::RemoteRecordClient(int portNum) {
    this->portNum = portNum;
}

/**
 * Receives audio from the server.
 * @param socket - The client socket.
 * @return 0 if message was successfully received and -1 otherwise.
 */
int RemoteRecordClient::receiveAudio(tcp::socket * socket) {
    int returnVal;
    char data[1024];
    size_t bytes_received;
    std::string messageReceived;

    // Loops while messages are being received successfully.
   for (;;) {
        // Receive data.
        try {
            // Clears the buffer.
            std::memset(data, 0, sizeof(data));

            // Receive data and sets message to the data.
            bytes_received = socket->read_some(boost::asio::buffer(data));
            messageReceived = std::string(data, data + bytes_received);
            returnVal = 0;
        } catch (std::exception& e) {
            returnVal = -1;
        }
    }

   return returnVal;
}

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
