#include "../include/scoreboard.h"

Scoreboard::Scoreboard(std::string imagepath, sf::Vector2f position_, const std::string path)
{
    this->imagepath = imagepath;
    position = sf::Vector2f(position_);
    image.loadFromFile(imagepath);
    image.createMaskFromColor(sf::Color::White);
    texture.loadFromImage(image);
    sprite.setOrigin(texture.getSize().x / 2, 0);
    sprite.setPosition(position.x, position.y);

    score.first = 0;
    score.second = 0;
    fontpath = path + "/game/images/arial.ttf";
    font.loadFromFile(fontpath);
    numbers.first.setFillColor(sf::Color::Black);
    numbers.second.setFillColor(sf::Color::Black);
    numbers.first.setStyle(sf::Text::Bold);
    numbers.second.setStyle(sf::Text::Bold);
    numbers.first.setCharacterSize(60);
    numbers.second.setCharacterSize(60);
}

void Scoreboard::update()
{
    
}

void Scoreboard::draw(sf::RenderWindow& window)
{
    sprite.setTexture(texture);
    numbers.first.setFont(font);
    numbers.second.setFont(font);

    numbers.first.setString(std::to_string(score.first));
    numbers.second.setString(std::to_string(score.second));
    numbers.first.setOrigin(numbers.first.getLocalBounds().width / 2, numbers.first.getLocalBounds().height);
    numbers.second.setOrigin(numbers.second.getLocalBounds().width / 2, numbers.second.getLocalBounds().height);
    float v_padding  = texture.getSize().y / 2;
    float h_padding = texture.getSize().x / 4; 
    numbers.first.setPosition(position.x - h_padding, position.y + v_padding);
    numbers.second.setPosition(position.x + h_padding, position.y + v_padding);

    window.draw(sprite);
    window.draw(numbers.first);
    window.draw(numbers.second);
}

sf::Vector2u Scoreboard::getSize()
{
    return texture.getSize();
}
