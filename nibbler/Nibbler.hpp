/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "../IGameModule.hpp"

class Nibbler : public IGameModule {
public:
    Nibbler();
    ~Nibbler();

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
protected:
    std::vector<std::string> _map;
    std::vector<std::string> _number_map;
    char _dir;
    int _size;
    unsigned int _game_time;
private:
};

extern "C" IGameModule *init() {
    return new Nibbler;
}

#endif /* !NIBBLER_HPP_ */
