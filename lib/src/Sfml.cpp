/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
    init();
}

Sfml::~Sfml()
{
    stop();
}

void    Sfml::init()
{
    std::cout << "SFML Library has been chosen" << std::endl;
}

void    Sfml::stop()
{
    std::cout << "SFML Library has been removed" << std::endl;
}
