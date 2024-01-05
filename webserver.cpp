#include "webserver.h"
#include <random>
#include <chrono>
#include <thread>

WebServer::WebServer(int id) : available(true), serverID(id), processingTimeLeft(0) {}

void WebServer::processRequest(const Request& request) {
    available = false;
    std::cout << "WebServer " << serverID << " is processing a request; IP In - " << request.getIPIn() << std::endl;

    // Random processing time between 1 and 5 seconds
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(4, 100); // Define the range

    int processingTime = distr(eng);
    std::this_thread::sleep_for(std::chrono::seconds(processingTime)); // Simulate processing

    std::cout << "WebServer " << serverID << " is done with a request after " << processingTime << " seconds; IP Out - " << request.getIPOut() << std::endl;
    available = true;
}

void WebServer::update() {
    if (!available && processingTimeLeft > 0) {
        processingTimeLeft--;
        if (processingTimeLeft == 0) {
            available = true;
        }
    }
}

bool WebServer::isAvailable() const {
    return available;
}

void WebServer::printStatus() const {
    std::cout << "WebServer " << serverID;
    if (available) {
        std::cout << " is free." << std::endl;
    } else {
        std::cout << " is processing a request." << std::endl;
    }
}

// void WebServer::displayRequestDetails(const Request& request) const {
//     std::cout << " IP In - " << request.getIPIn()
//               << ", IP Out - " << request.getIPOut()
//               << std::endl;
// }


