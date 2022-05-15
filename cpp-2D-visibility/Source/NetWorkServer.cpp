#include <NetworkServer.hpp>

NetWorkServer::NetWorkServer() {
    ip_ = sf::IpAddress::getLocalAddress();
}

sf::IpAddress NetWorkServer::getIp() const {
    return ip_;
}