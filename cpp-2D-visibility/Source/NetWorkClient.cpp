#include <NetworkClient.hpp>

NetWorkClient::NetWorkClient() {
    ip_ = sf::IpAddress::getLocalAddress();
    std::cout << ip_ << std::endl;
}