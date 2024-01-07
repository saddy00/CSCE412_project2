#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <queue>
#include "request.h"
#include "webserver.h"
#include <vector>

class LoadBalancer {
public:
    LoadBalancer(int numberOfServers, int runTime);
    ~LoadBalancer();
    void addRequest(const Request& request);
    void run();
    void printServerStatuses() const;

private:
    std::queue<Request> requestQueue;
    std::vector<WebServer> webServers;
    int runTime; // Store the runtime of the simulation
};

#endif