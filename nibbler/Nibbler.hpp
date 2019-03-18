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
    void    play();
    char    *test();
    std::vector<std::string> get_map();
    // std::list<std::string>  getStartMap();    

protected:
    bool    hasInit;
    std::vector<std::string> _map;
private:
};

extern "C" IGameModule *init() {
    return new Nibbler;
}

#endif /* !NIBBLER_HPP_ */
