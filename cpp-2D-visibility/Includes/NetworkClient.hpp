#pragma once
#include <iostream>

//headers
#include <SFML/Network.hpp>

class NetWorkClient {
  public:
    sf::Socket::Status Init(unsigned short preferablePort = sf::Socket::AnyPort);
    sf::Socket::Status RegisterOnServer();
    sf::Socket::Status SendRegisterClientData();
  private:
    std::string name_;

    unsigned short reg_port_; //for TCP connection
    unsigned short server_udp_port_;
    sf::IpAddress server_ip_;
    sf::TcpSocket reg_socket_;
    sf::UdpSocket data_socket_;
};