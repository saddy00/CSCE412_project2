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

private:
    bool available;
    int serverID;
    int processingTimeLeft;
    std::string currentIPOut;
};

#endif