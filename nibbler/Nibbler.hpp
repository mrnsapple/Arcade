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

protected:
    bool    hasInit;
    std::vector<std::string> _map;
    std::vector<std::string> _number_map;

    char _dir;
    int _size;
private:
};

extern "C" IGameModule *init() {
    return new Nibbler;
}

#endif /* !NIBBLER_HPP_ */
