/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** RectObject
*/

#ifndef RECTOBJECT_HPP_
#define RECTOBJECT_HPP_

#include <SFML/Graphics.hpp>

class RectObject {
public:
    sf::RectangleShape  shape;
    RectObject(float x, float y) {
        shape.setPosition(x, y);
        shape.setSize({20, 20});
    }

protected:
private:
};

#endif /* !RECTOBJECT_HPP_ */
