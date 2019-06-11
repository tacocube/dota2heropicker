#include <pistache/http.h>
#include <hellohandler.hpp>
#include <iostream>
#include <string>

int getPort() {
    char* port_str = std::getenv("PORT");
    if (port_str == nullptr) {
        return 9080;
    } else {
        std::stringstream ss(port_str);
        int port_int;
        ss >> port_int;
        return port_int;
    }
}

int main() {
    int portNum = getPort();
    std::clog << "Listening on port " << portNum << std::endl;
    Pistache::Http::listenAndServe<HelloHandler>(std::string("*:") + std::to_string(portNum));
    return 0;
}