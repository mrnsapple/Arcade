/*
** EPITECH PROJECT, 2019
** pacman
** File description:
** by oriol
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

#include "../IGameModule.hpp"

class Pacman : public IGameModule {
public:
    Pacman();
    ~Pacman();

    void    init();
    bool    play();
    char    *test();
    std::vector<std::string> get_map();
    bool    know_head(int x, int y);
    // std::list<std::string>  getStartMap();    
    void    move_top(int x, int y);
    void    move_bot(int x, int y);
    void    move_left(int x, int y);
    void    move_rigth(int x, int y);
    void    set_dir(char dir);
    int     get_size();
    void    increase_numbers_map(int x, int y, char dol);
    void    number_map_to_map();
    std::vector<std::string> get_number_map();
    bool move_ghost(int gost_y, int gost_x, int y, int x);
    void    initialize_values();
    int    get_game_time();
    void    time_to_eat_stuff();

protected:
    bool    hasInit;
    std::vector<std::string> _map;
    std::vector<std::string> _number_map;
    char _dir;
    int _size;
    int _game_time;
    int _time_to_eat;

private:
};

extern "C" IGameModule *init() {
    return new Pacman;
}

#endif