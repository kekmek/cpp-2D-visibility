#include <iostream>
#include <string>

#include "Game.hpp"
#include "NetworkServer.hpp"
#include "NetworkClient.hpp"


int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Incorrect type of Server/Client" << std::endl;
        return 0;

    } else {
        NetWorkServer Server;
        NetWorkClient Client;
        sf::TcpSocket socket;
        
        if( static_cast<std::string>(argv[1]) == "Server" ) {
            sf::TcpListener listener;
            listener.listen(2000);

            if(listener.accept(socket) != sf::Socket::Done) {
                std::cout << "Failure to accept" << std::endl;
                return 0;
            }

        } else if( static_cast<std::string>(argv[1]) == "Client" ) {
           sf::Socket::Status status = socket.connect(Server.getIp(), 2000);
           if(status != sf::Socket::Done) {
               std::cout << "Failure to connect" << std::endl;
               return 0;
           } 
        }
        socket.setBlocking(false);

    }
    return 0;
}