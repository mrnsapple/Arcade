/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** TextObject
*/

#ifndef TEXTOBJECT_HPP_
#define TEXTOBJECT_HPP_

#include <SFML/Graphics.hpp>

class TextObject {
public:
    sf::Text    text;
    sf::Font    font;

    TextObject(float x, float y) {
        font.loadFromFile("./lib/src/font.ttf");
        text.setFont(font);
        text.setCharacterSize(22);
        text.setPosition(x, y);
        text.setFillColor(sf::Color::White);
    }

    void    setText(const sf::String &string) { text.setString(string); }

protected:
private:
};

#endif /* !TEXTOBJECT_HPP_ */
