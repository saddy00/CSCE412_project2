#include "webserver.h"
#include <random>
#include <chrono>

WebServer::WebServer(int id) : available(true), serverID(id), processingTimeLeft(0) {}

void WebServer::processRequest(const Request& request) {
    available = false;
    currentIPOut = request.getIPOut();
    std::cout << "WebServer " << serverID << " is processing a request; IP In - " << request.getIPIn() << std::endl;

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(4, 100); // Random processing time between 4 and 100 seconds
    processingTimeLeft = distr(eng);
}

void WebServer::update() {
    if (!available && processingTimeLeft > 0) {
        processingTimeLeft--;
        if (processingTimeLeft == 0) {
            available = true;
            std::cout << "WebServer " << serverID << " is done; IP Out - " << currentIPOut << std::endl; // Printing server is free
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
