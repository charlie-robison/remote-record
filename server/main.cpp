#include <iostream>
#include "LivePlayServer.h"

int main() {
    auto livePlayServer = LivePlayServer();

    // Runs the live play server and checks if it is running.
    if (livePlayServer.runServer() < 0) {
        std::cout << "Server Error";
    }

    return 0;
}
