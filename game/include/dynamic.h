#pragma once
#include "library.h"

#define MAX_POS_X 200
#define MAX_POS_Y 200
#define MIN_POS_X 0
#define MIN_POS_Y 0
#define RADIUS 10
#define DEFAULT_MASS 10

class DynamicObject {
    protected:
    sf::Vector2f position;

    public:
    void set_coord(sf::Vector2f new_pos);

};

class ClientDynamicObject : public DynamicObject {
    private:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    std::string imagepath;

    public:
    ClientDynamicObject() = default;
    ClientDynamicObject(std::string imagepath);
    void draw(sf::RenderWindow& window);
};

class ServerDynamicObject : public DynamicObject {
    private:
    sf::Vector2f speed;

    public:
    const float mass;
    ServerDynamicObject();
    ServerDynamicObject(float);
    sf::Vector2f get_coord();
    sf::Vector2f update(ServerDynamicObject&, ServerDynamicObject&);
    sf::Vector2f calculate_speed(sf::Vector2f);
    sf::Vector2f calculate_speed();
};