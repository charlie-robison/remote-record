#include <iostream>
#include "RemoteRecordClient.h"

int main(int argc, char * argv []) {
    int portNum;

    // Checks the number of args.
    if (argc == 2) {
        portNum = atoi(argv[1]);
        auto remoteRecordClient = RemoteRecordClient(portNum);
        remoteRecordClient.connectToServer();
    } else {
        std::cout << "Incorrect number of args." << std::endl;
    }

    return 0;
}
