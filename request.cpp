#include "request.h"
#include <cstdlib> 

Request::Request() {
    // Generate random IPs and time
    ip_in = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    ip_out = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    time = rand() % 97 + 4; // Random time between 4 and 100
}

std::string Request::getIPIn() const {
    return ip_in;
}

std::string Request::getIPOut() const {
    return ip_out;
}

int Request::getTime() const {
    return time;
}
