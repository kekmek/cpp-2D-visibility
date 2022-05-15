#pragma once

//headers
#include <SFML/Network.hpp>

struct client {

};

class NetWorkServer {
 public:
    NetWorkServer();
    sf::IpAddress getIp() const;

 private:

    sf::IpAddress ip_;
};