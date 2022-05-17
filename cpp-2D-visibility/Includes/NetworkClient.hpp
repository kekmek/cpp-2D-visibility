#pragma once
#include <iostream>

//headers
#include <SFML/Network.hpp>
#include "Heroes.hpp"
#include <string>

class NetWorkClient {
  public:
    sf::Socket::Status Init(unsigned short preferablePort = sf::Socket::AnyPort);
    sf::Socket::Status RegisterOnServer();
    sf::Socket::Status SendData(const Hero& tank);
    sf::Socket::Status ReceiveData(Hero& tank_friend);

  private:
    sf::Socket::Status SendRegisterClientData();
    sf::Socket::Status ReceiveServerUdpPort(); //getting udp port of Server

    std::string name_;

    sf::Packet packet_;

    unsigned short reg_port_; //for TCP connection
    unsigned short server_udp_port_;
    sf::IpAddress server_ip_;
    sf::TcpSocket reg_socket_;
    sf::UdpSocket data_socket_;
};