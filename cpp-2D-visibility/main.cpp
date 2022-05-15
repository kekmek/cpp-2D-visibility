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
        if( static_cast<std::string>(argv[1]) == "Server" ) {
            
        } else if( static_cast<std::string>(argv[1]) == "Client" ) {
            NetWorkClient Client;
            
        }
    }
    return 0;
}