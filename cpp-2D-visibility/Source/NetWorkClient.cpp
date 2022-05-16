#include <NetworkClient.hpp>

sf::Socket::Status NetWorkClient::Init() {
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
    std::cin >> tmp;
    return sf::Socket::Status::Done;
}