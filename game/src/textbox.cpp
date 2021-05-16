#include "../include/textbox.h"

TextBox::TextBox(sf::Text& suggestion)
{
    sf::FloatRect bounds(suggestion.getGlobalBounds());
    box.setSize({bounds.width, bounds.height});
    box.setFillColor(sf::Color::White);
    sf::Vector2f origin(box.getSize().x / 2, box.getSize().y / 2);
    box.setOrigin(origin);
    sf::Vector2f position(suggestion.getPosition().x, suggestion.getPosition().y + 2 * origin.y);
    box.setPosition(position);

    font = suggestion.getFont();
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(static_cast<unsigned int>(suggestion.getCharacterSize() * 0.7));
    text.setPosition(position);
    text.setOrigin(origin);
}

void TextBox::draw(sf::RenderWindow& window)
{
    text.setFont(*font);
    text.setString(text_s);
    if ()
    std::cout << text.getLocalBounds().width << " " << box.getLocalBounds().width << std::endl;
    window.draw(box);
    window.draw(text);
}

std::string TextBox::get_text()
{
    return text.getString().toAnsiString();
}

void TextBox::update(sf::Event& event)
{
    switch ( event.text.unicode ) {
        case 0x8://Backspace
        if ( !text_s.isEmpty() )
            text_s.erase(text_s.getSize()-1) ;
        break ;
        default :
             text_s += static_cast<wchar_t>(event.text.unicode) ;
             //std::cout << "new: " << text_s.toAnsiString() << std::endl;
        }
}
