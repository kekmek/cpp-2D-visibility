#pragma once
#include <iostream>

//headers
#include <SFML/Network.hpp>

class NetWorkClient {
 public:
    NetWorkClient();
    NetWorkClient(const NetWorkClient& another) {printf("copy");}
    NetWorkClient(const NetWorkClient&& another) {printf("move");}
 private:
    sf::IpAddress ip_;
};