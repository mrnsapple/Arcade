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
        font.loadFromFile("./assets/font.ttf");
        text.setFont(font);
        text.setCharacterSize(22);
        text.setPosition(x, y);
        text.setFillColor(sf::Color::White);
        highlighted = false;
    }

    void    setText(const sf::String &string) { text.setString(string); }
    void    blink(sf::Color color = sf::Color::Red) {
        text.setOutlineColor(color);
        if (!highlighted && frame.getElapsedTime().asMilliseconds() >= 150) {
            text.setOutlineThickness(2);
            highlighted = true;
            frame.restart();
        }
        if (highlighted && frame.getElapsedTime().asMilliseconds() >= 150) {
            text.setOutlineThickness(0);
            highlighted = false;
            frame.restart();
        }
    }


protected:
private:
    bool    highlighted;
    sf::Clock   frame;
};

#endif /* !TEXTOBJECT_HPP_ */
