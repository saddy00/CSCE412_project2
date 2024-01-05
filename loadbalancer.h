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
    void distributeRequest();
    void run(); // New method to run the load balancing process
    void printServerStatuses() const; // New method to print server statuses

private:
    std::queue<Request> requestQueue;
    std::vector<WebServer> webServers;
    int runTime; // Store the runtime of the simulation
};

#endif



// randomly add the servers and remove servers
// you could add the server numbers and also how many are in the queue or not after that 