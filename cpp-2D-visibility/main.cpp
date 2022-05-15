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
            std::cout << Server.getIp() << std::endl;
            sf::TcpListener listener;
            listener.listen(2000);

            if(listener.accept(socket) != sf::Socket::Done) {
                std::cout << "Failure to accept" << std::endl;
                return 0;
            }

        } else if( static_cast<std::string>(argv[1]) == "Client" ) {
            std::cout << "Enter IP Address" << std::endl;
            std::string ip;
            std::cin >> ip;
            sf::Socket::Status status = socket.connect(ip, 2000);
            if(status != sf::Socket::Done) {
                std::cout << "Failure to connect" << std::endl;
                return 0;
            } 
        }
        std::string name;
        std::cout << "Enter your name:\n";
        std::cin  >> name;

        socket.setBlocking(false);

        std::string message = "";
    sf::Packet  packet;

    while(true)
    {
        std::cin >> message;

        if(message != "")
        {
            packet.clear();
            packet << name << message;

            socket.send(packet);

            message = "";
        }

        if(socket.receive(packet) == sf::Socket::Done)
        {
            std::string nameRec;
            std::string messageRec;

            packet    >> nameRec >> messageRec;
            std::cout << nameRec << ": " << messageRec << '\n';
        }
    }

    }
    return 0;
}