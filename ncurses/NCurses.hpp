/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <curses.h>
#include "../IDisplayModule.hpp"
#include <stdlib.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

class NCurses : public IDisplayModule {
public:
    NCurses();
    ~NCurses();

    void    init();
    void    start();
    void    stop();
    void    get_keypad(void);
    void    print_map(void);
    std::string setUserName();

protected:
private:
    int _key_press;
};

extern "C" IDisplayModule *init() {
    return new NCurses;
}

#endif /* !NCURSES_HPP_ */
