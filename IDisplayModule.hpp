/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <iostream>
#include <string>
#include <dlfcn.h>
#include <unistd.h>
#include <fstream>
#include <dirent.h>
#include <sstream>
#include <vector>
#include "IGameModule.hpp"

class IDisplayModule {
public:
    virtual ~IDisplayModule() = default;
    virtual void    init() = 0;
    virtual    IGameModule *  start(IGameModule *game) = 0;
    virtual void    stop() = 0;
    virtual bool    required_actions() = 0;
    virtual void    game_loop() = 0;
    virtual void    initialize_values() = 0;
    virtual std::string get_graph_lib() = 0;

protected:
private:
};

typedef IDisplayModule  *init_t();

#endif /* !IDISPLAYMODULE_HPP_ */
