#include "loadbalancer.h"
#include <functional> 

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
    for (int i = 0; i < webServers.size(); ++i) {
        if (!requestQueue.empty()) {
            webServers[i].startProcessing(requestQueue.front());
            int completionTime = currentCycle + webServers[i].getExpectedCompletionTime();
            taskQueue.push(ServerTask(i+1, completionTime));
            requestQueue.pop();
        }
    }

    while (currentCycle < runTime && (!requestQueue.empty() || !taskQueue.empty())) {
        if (!taskQueue.empty()) {
            ServerTask currentTask = taskQueue.top();
            if (currentTask.completionTime <= currentCycle) {
                taskQueue.pop();
                // Check if more requests are pending
                if (!requestQueue.empty()) {
                    webServers[currentTask.serverID - 1].startProcessing(requestQueue.front());
                    int newCompletionTime = currentCycle + webServers[currentTask.serverID - 1].getExpectedCompletionTime();
                    taskQueue.push(ServerTask(currentTask.serverID, newCompletionTime));
                    requestQueue.pop();
                }
            }
        }
        // Update all servers
        for (auto &server : webServers) {
            server.update();
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
