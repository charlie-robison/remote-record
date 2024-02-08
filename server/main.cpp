#include <iostream>
#include "RemoteRecordServer.h"

int main(int argc, char * argv[]) {
    int portNum;

    // Checks if the correct number of args are given.
    if (argc == 2) {
        portNum = atoi(argv[1]);
        auto remoteRecordServer = RemoteRecordServer(portNum);
        remoteRecordServer.startServer();
    } else {
        std::cout << "Wrong number of arguments given." << std::endl;
    }

    return 0;
}
