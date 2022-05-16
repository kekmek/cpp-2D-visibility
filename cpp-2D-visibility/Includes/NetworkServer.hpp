#pragma once

//headers
#include <SFML/Network.hpp>
#include <string>
#include <iostream>

struct Client {
  std::string name;

};

class NetWorkServer {
  public:
    NetWorkServer();
    sf::IpAddress getIp() const;
    sf::Socket::Status Init();
    sf::Socket::Status AcceptNewConnections();

  private:
    std::array<Client, 2> clients_;
    sf::TcpListener listener_;
    sf::TcpSocket reg_socket_;
    sf::IpAddress ip_;
};