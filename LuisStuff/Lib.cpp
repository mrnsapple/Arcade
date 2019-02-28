/*
** EPITECH PROJECT, 2019
** OOP
** File description:
** Lib
*/

#include "Lib.hpp"

Lib::Lib()
{
    _name = "lib";
    init();
}

Lib::~Lib()
{
    stop();
}

void    Lib::init() 
{
    std::cout << getName() <<" made" << std::endl;
}

void    Lib::stop() 
{
    std::cout << getName() << " deleted" << std::endl;
}
