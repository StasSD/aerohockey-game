#include "client.h"
#include "server.h"
#include <iostream>

Client::Client() {
    addr = sf::IpAddress::Any;
    port = sf::Socket::AnyPort;
    if (socket.bind(port) != sf::Socket::Done) {
        std::cerr << "Error binding client socket." << std::endl;
    }
    // do not block socket
    socket.setBlocking(false);
    std::cout << "Initializing client." << std::endl;
}

Client::~Client() {
    socket.unbind();
}

bool Client::send_updates(sf::Packet& packet, sf::IpAddress server_addr) {
    if (socket.send(packet, server_addr, PORT) != sf::Socket::Done) {
        return false;
    }
    return true;
}

bool Client::receive_updates(sf::Packet& packet, sf::IpAddress& server_addr, unsigned short& port) {
    if (socket.receive(packet, server_addr, port) != sf::Socket::Done) {
        return false;
    }
    return true;
}

void Client::connect(sf::IpAddress server_addr) {
    sf::Packet connection_info;
    if (socket.send(connection_info, server_addr, PORT) != sf::Socket::Done) {
        std::cerr << "Error establishing connection to server." << std::endl;
    }
}


sf::Packet Client::process_input() {

    // test version for processing input
    // NetworkPacket data;

    float pos1_x = 1.0f;
    float pos1_y = 1.0f;
    // data.pos2_x = 2.0f;
    // data.pos2_y = 2.0f;
    // data.puck_x = 3.0f;
    // data.puck_y = 3.0f;

    sf::Packet packet;
    packet << pos1_x << pos1_y;

    return packet;
}

sf::Time Client::get_update_time(Game& game) {
    return game.get_update_time();
}
