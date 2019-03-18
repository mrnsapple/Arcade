/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <curses.h>
#include "IDisplayModule.hpp"

class NCurses : public IDisplayModule {
public:
    NCurses();
    ~NCurses();

    void    init();
    void    start();
    void    stop();
    std::string setUserName();

protected:
private:
};

extern "C" IDisplayModule *init() {
    return new NCurses;
}

#endif /* !NCURSES_HPP_ */
