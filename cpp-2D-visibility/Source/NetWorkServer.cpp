#include <NetworkServer.hpp>

NetWorkServer::NetWorkServer() {
    ip_ = sf::IpAddress::getLocalAddress();
}

sf::IpAddress NetWorkServer::getIp() const {
    return ip_;
}

sf::Socket::Status NetWorkServer::Init() {
    if(listener_.listen(sf::Socket::AnyPort) == sf::Socket::Status::Done) {
        std::cout << "Server's Port: ";
        std::cout << listener_.getLocalPort() << std::endl;
        return sf::Socket::Status::Done;
    }else {
        return sf::Socket::Status::Error;
    }
}

sf::Socket::Status NetWorkServer::AcceptNewConnections() {
    if(listener_.accept(reg_socket_) != sf::Socket::Status::Done) {
        std::cout << "Failure to accept" << std::endl;
        return sf::Socket::Status::Error;
    }else {
        std::cout << "New client connected: " << reg_socket_.getRemoteAddress() << std::endl;
        return sf::Socket::Status::Done;
    }
}