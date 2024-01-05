#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"
#include <iostream>

class WebServer {
public:
    WebServer(int id);
    void processRequest(const Request& request);
    void printStatus() const;
    bool isAvailable() const;
    void update();
    // void displayRequestDetails(const Request& request) const;
private:
    bool available;
    int serverID;
    int processingTimeLeft; 
    void displayRequestDetails(const Request& request) const;
};

#endif
