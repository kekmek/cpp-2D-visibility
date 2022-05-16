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
        std::cout << "Waiting Clients" << std::endl;
         return sf::Socket::Status::Done;
    }else {
        return sf::Socket::Status::Error;
    }
}

sf::Socket::Status NetWorkServer::RegisterNewClients() {
    return ReceiveClientsRegData();
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

sf::Socket::Status NetWorkServer::ReceiveClientsRegData() {
    //if(reg_socket_.isBlocking()) reg_socket_.setBlocking(false);
    int i = 0;
    while( i < max_quan_clients) {
        AcceptNewConnections();
        if(reg_socket_.receive(packet_) == sf::Socket::Status::Done) {
            if(packet_.getDataSize() > 0) {
                Client new_client;
                packet_ >> new_client.name;
                packet_ >> new_client.port;
                new_client.ip = reg_socket_.getRemoteAddress();
                new_client.data_socket = new sf::UdpSocket;
                new_client.data_socket->bind(sf::Socket::AnyPort);
                ++i;
                clients_.push_back(new_client);
                reg_socket_.disconnect();
                packet_.clear();
            }else {
                std::cout << "Packet is empty" << std::endl;
                return sf::Socket::Status::Error; 
            }
        }else {
            std::cout << "Failure to receive packet" << std::endl;
            return sf::Socket::Status::Error;
        }
    }
    for(auto& client : clients_) {
        std::cout << client.name << std::endl;
    }
    return sf::Socket::Status::Done;
}

NetWorkServer::~NetWorkServer() {
    for(auto client : clients_) {
        delete client.data_socket;
    }
}