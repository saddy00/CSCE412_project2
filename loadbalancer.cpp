#include "loadbalancer.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

LoadBalancer::LoadBalancer(int numberOfServers, int runTime) : runTime(runTime) {
    for (int i = 0; i < numberOfServers; ++i) {
        webServers.push_back(WebServer(i+1));
    }
}

LoadBalancer::~LoadBalancer() {
}

void LoadBalancer::addRequest(const Request& request) {
    requestQueue.push(request);
}


void LoadBalancer::run() {
    int currentCycle = 0;
    bool initialProcessingShown = false;
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, 100); // Adjust as needed for frequency of new requests

    while (true) {
        // Add new requests at random
        if (distr(eng) == 1) {
            int newRequests = distr(eng); // Random number of new requests
            for (int i = 0; i < newRequests; ++i) {
                addRequest(Request(/* parameters */));
            }
            std::cout << "Queue Size: " << requestQueue.size() << " (+" << newRequests << " new requests)" << std::endl;
        }

        // Update and assign requests to servers
        for (auto &server : webServers) {
            server.update();
            if (server.isAvailable() && !requestQueue.empty()) {
                server.processRequest(requestQueue.front());
                requestQueue.pop();
            }
        }

        if (!initialProcessingShown) {
            // printServerStatuses();
            initialProcessingShown = true;
        }

        // Adjust number of servers every 20 cycles
        if (currentCycle % 20 == 0) {
            int requestsPerServer = requestQueue.size() / webServers.size();
            if (requestsPerServer > 20 && webServers.size() < 100) { // Limit max servers to 100
                webServers.push_back(WebServer(webServers.size() + 1));
                std::cout << "Adding a new server to help with the queue. Total servers: " << webServers.size() << std::endl;
            } else if (requestsPerServer < 15 && webServers.size() > 1) {
                webServers.pop_back();
                std::cout << "Removing a server as the load decreases. Total servers: " << webServers.size() << std::endl;
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
        currentCycle++;
    }
    std::cout << "Load balancer run completed." << std::endl;
}

void LoadBalancer::printServerStatuses() const {
    for (const auto& server : webServers) {
        server.printStatus();
    }
}
