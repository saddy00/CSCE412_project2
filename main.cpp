#include "loadbalancer.h"
#include <iostream>

int main() {
    int numServers, runTime;
    std::cout << "Enter number of web servers: ";
    std::cin >> numServers;
    std::cout << "Enter the run time for the load balancer: ";
    std::cin >> runTime;

    LoadBalancer loadBalancer(numServers, runTime);

    // Generate initial full queue (servers * 20)
    for (int i = 0; i < numServers * 20; ++i) {
        loadBalancer.addRequest(Request());
    }

    loadBalancer.run(); // Run the load balancing simulation

    return 0;
}

