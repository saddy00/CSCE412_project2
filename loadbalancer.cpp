#include "loadbalancer.h"

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

void LoadBalancer::distributeRequest() {
    while (!requestQueue.empty()) {
        for (auto& server : webServers) {
            if (server.isAvailable() && !requestQueue.empty()) {
                server.processRequest(requestQueue.front());
                requestQueue.pop();
            }
        }
    }
}

void LoadBalancer::run() {
    int currentCycle = 0;

    // Initially assign requests to all servers
    for (auto &server : webServers) {
        if (!requestQueue.empty()) {
            server.processRequest(requestQueue.front());
            requestQueue.pop();
        }
    }

    while (currentCycle < runTime && !requestQueue.empty()) {
        for (auto &server : webServers) {
            server.update(); // Update each server's status

            if (server.isAvailable() && !requestQueue.empty()) {
                server.processRequest(requestQueue.front());
                requestQueue.pop();
            }
        }

        // Print status of each web server
        printServerStatuses();

        // Simulate the passage of one clock cycle
        currentCycle++;
    }

    std::cout << "Load balancer run completed." << std::endl;
}

void LoadBalancer::printServerStatuses() const {
    for (const auto& server : webServers) {
        server.printStatus();
    }
}
