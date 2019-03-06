/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <iostream>
#include <string>

class IGameModule {
public:
    virtual ~IGameModule() = default;
    virtual void    init() = 0;
    virtual void    play() = 0;

protected:
private:
};

typedef IGameModule *init_t();

#endif /* !IGAMEMODULE_HPP_ */
