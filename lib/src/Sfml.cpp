/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
    // init();
    _win = new sf::RenderWindow({820, 580}, "Arcade", sf::Style::Default);
}

Sfml::~Sfml()
{
    // stop();
}

void    Sfml::init()
{
    std::cout << "SFML Library has been chosen" << std::endl;
    while (_win->isOpen()) {
        stop();
        _win->clear();
        _win->display();
    }
}

void    Sfml::stop()
{
    while (_win->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _win->close();
            std::cout << "SFML Library has been removed" << std::endl;
        }
    }
}
