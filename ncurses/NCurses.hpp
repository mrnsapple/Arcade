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
#include <string.h>

class NCurses : public IDisplayModule {
public:
    NCurses();
    ~NCurses();

    void    init();
     IGameModule *    start(IGameModule *game);
    void    stop();
    void    NextLib();
    void    PrevLib();
    void    NextGame();

    void    my_refresh();
    void    get_keypad(void);
    void    get_keypad_not_wait(void);

    void    print_map(void);

    void    get_name();
    bool    get_lib();
    void    get_game();
    void    inside_get_game();
    void    specify_game(char *path_to_game);
    bool    required_actions();
    void    game_loop();
    void    initialize_values();
    std::string get_graph_lib();
    void    set_direc();
    void    print_print_info(int pos, const char *content);

    std::string print_score();


protected:
private:
    int _key_press;
    std::string _user_name;
     IGameModule *_game;
    std::string _game_name;
    std::vector<std::string> _available_game_names;
    std::map<std::string, std::string> _available_game;
    std::string _graphic_lib;
    std::vector<std::string> _print_info;
    int _prev_library;

};

extern "C" IDisplayModule *init() {
    return new NCurses;
}

#endif /* !NCURSES_HPP_ */
