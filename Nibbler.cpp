/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
{
    hasInit = false;
}

Nibbler::~Nibbler()
{
}

void    Nibbler::init()
{
    if (hasInit == false) {
        std::cout << "TIME TO INITIALIZE" << std::endl;
        // title = new TextObject(5, 25);
        // title->setText("NIBBLER MY DUDE");
        hasInit = true;
    }
}

void    Nibbler::play()
{
    std::cout << "TIME TO PLAY" << std::endl;
}