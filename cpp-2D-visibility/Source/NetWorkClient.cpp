#include <NetworkClient.hpp>

sf::Socket::Status NetWorkClient::Init(unsigned short preferablePort) {
    std::cout << "Enter Server's IpAddress" << std::endl;
    std::string tmp;
    std::getline(std::cin, tmp);

    server_ip_ = sf::IpAddress(tmp);
    
    std::cout << "Enter Server's Port" << std::endl;
    std::cin >> reg_port_;

    sf::Socket::Status status = reg_socket_.connect(server_ip_, reg_port_);
    if(status != sf::Socket::Status::Done) {
        std::cout << "Failure to connect" << std::endl;
        return status;
    }

    tmp.clear();
    std::cout << "Enter Your Name" << std::endl;
    std::cin >> name_;

    if(data_socket_.bind(preferablePort) == sf::Socket::Status::Done) {
        std::cout << "Successfully binded to port:" << data_socket_.getLocalPort() << std::endl;
    }else {
        std::cout << "Failure to bind" << std::endl;
        return sf::Socket::Status::Error;
    }
    return sf::Socket::Status::Done;
}

sf::Socket::Status NetWorkClient::RegisterOnServer() {
    return SendRegisterClientData();
}

sf::Socket::Status NetWorkClient::SendRegisterClientData() {
    if(!reg_socket_.isBlocking()) reg_socket_.setBlocking(true);

    sf::Packet packet;
    packet << name_ << data_socket_.getLocalPort();
    if(reg_socket_.send(packet) == sf::Socket::Status::Done) {
        std::cout << "SendRegisterClientData() : Successfully" << std::endl;
    }else {
        std::cout << "Failed to send client data" << std::endl;
        return sf::Socket::Status::Error;
    }
    
}