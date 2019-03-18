/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <iostream>
#include <string>
#include <list>
#include <vector>

class IGameModule {
public:
    virtual ~IGameModule() = default;
    virtual void    init() = 0;
    virtual bool    play() = 0;
    virtual char *   test() = 0;
    virtual std::vector<std::string> get_map() = 0;
    virtual std::vector<std::string> get_number_map() = 0;

    // virtual std::list<std::string>  getStartMap() = 0;


protected:
private:
};

typedef IGameModule *init_g();

#endif /* !IGAMEMODULE_HPP_ */
