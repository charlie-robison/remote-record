#include <iostream>
#include "LivePlayServer.h"

int main() {
    auto livePlayServer = LivePlayServer();

    // Runs the live play server and checks if it is running.
    if (livePlayServer.runServer() == 0) {
        std::cout << "Server is running on port 13...";
    } else {
        std::cout << "Error is server creation!";
    }

    return 0;
}
