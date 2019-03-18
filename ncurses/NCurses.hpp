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
#include <iostream>
#include <string>
class NCurses : public IDisplayModule {
public:
    NCurses();
    ~NCurses();

    void    init();
    void    start();
    void    stop();
    void    my_refresh();
    void    get_keypad(void);
    void    print_map(void);
    void    get_name();
    std::string setUserName();

protected:
private:
    int _key_press;
    std::string _user_name;
};

extern "C" IDisplayModule *init() {
    return new NCurses;
}

#endif /* !NCURSES_HPP_ */
