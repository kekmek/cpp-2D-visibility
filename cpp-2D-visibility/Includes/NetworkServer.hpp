#pragma once

//headers
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <vector>

struct Client {
  std::string name;
  sf::IpAddress ip;
  unsigned short port;
  sf::UdpSocket* data_socket;
};

class NetWorkServer {
  public:
    NetWorkServer();
    sf::IpAddress getIp() const;
    sf::Socket::Status Init();
    sf::Socket::Status RegisterNewClients();
    sf::Socket::Status AcceptNewConnections();
    sf::Socket::Status ReceiveClientsRegData();
    ~NetWorkServer();
  private:
    std::vector<Client> clients_;
    sf::TcpListener listener_;
    sf::TcpSocket reg_socket_;
    sf::IpAddress ip_;
    sf::Packet packet_;

    unsigned short max_quan_clients = 2;
};