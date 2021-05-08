#include "client.h"
#include "server.h"
#include <iostream>

Client::Client() {
    addr = sf::IpAddress::Any;
    port = sf::Socket::AnyPort;
    if (socket.bind(port) != sf::Socket::Done) {
        std::cerr << "Error binding client socket." << std::endl;
    }
    std::cout << "Initializing client." << std::endl;
}

Client::~Client() {
    socket.unbind();
}

void Client::connect(sf::IpAddress server_addr) {
    sf::Packet connection_info;
    if (socket.send(connection_info, server_addr, PORT) != sf::Socket::Done) {
        std::cerr << "Error establishing connection to server." << std::endl;
    }
}