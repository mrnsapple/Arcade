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
#include "../IGameModule.hpp"
#include <stdlib.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <map>

class NCurses : public IDisplayModule {
public:
    NCurses();
    ~NCurses();

    void    init();
    void    start();
    void    stop();
    void    NextLib();
    void    PrevLib();

    void    my_refresh();
    void    get_keypad(void);
    void    get_keypad_not_wait(void);

    void    print_map(void);

    void    get_name();
    void    get_game();
    void    specify_game(char *path_to_game);
    void    required_actions();
    void    game_loop();
    void    initialize_values();

    void    set_direc();
    std::string setUserName();

protected:
private:
    int _key_press;
    std::string _user_name;
     IGameModule *_game;
    std::string _game_name;
    std::vector<std::string> _available_game_names;
    std::vector<std::string> _available_game_libraries;
    std::map<std::string, std::string> _available_game;

};

extern "C" IDisplayModule *init() {
    return new NCurses;
}

#endif /* !NCURSES_HPP_ */
