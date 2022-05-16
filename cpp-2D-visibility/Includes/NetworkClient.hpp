#pragma once
#include <iostream>

//headers
#include <SFML/Network.hpp>

class NetWorkClient {
  public:
    sf::Socket::Status Init();
    
  private:
    
    unsigned short reg_port_;
    sf::IpAddress server_ip_;
    sf::TcpSocket reg_socket_;
    sf::UdpSocket data_socket_;
};