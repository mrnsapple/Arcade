/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "IGameModule.hpp"
#include "sfml/TextObject.hpp"

class Nibbler : public IGameModule {
public:
    Nibbler();
    ~Nibbler();

    void    init();
    void    play();

protected:
    TextObject  *title;
    bool    hasInit;
private:
};

extern "C" IGameModule *init() {
    return new Nibbler;
}

#endif /* !NIBBLER_HPP_ */
