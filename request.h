#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Request {
public:
    Request(); // Constructor to initialize a request

    std::string getIPIn() const; // Getter for IP in
    std::string getIPOut() const; // Getter for IP out
    int getTime() const; // Getter for processing time

private:
    std::string ip_in; // Store IP in
    std::string ip_out; // Store IP out
    int time; // Store processing time
};

#endif
