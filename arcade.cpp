/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** arcade
*/

#include <iostream>
#include <string>
#include <dlfcn.h>
#include "IDisplayModule.hpp"
#include <string.h>

IGameModule *game = NULL;

void    printUsage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t   ./arcade lib" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\t   lib\tgraphical dynamic library (e.j. lib_arcade_sfml.so)" << std::endl;
    std::cout << "In ncurses:\n\t Esq key->exit game\n\tEnter key->restart_game\n\tp key->go back to menu\n\tz key->prev game\n\tx key->next game\n\tj key->prev graphic lib\n\tl key->next graphic lib\n";
}

int main(int ac, char **av)
{
    std::string graph_lib;

    if (ac == 2) {
        void    *handle = dlopen(av[1], RTLD_LAZY);
        if (!handle) {
            std::cerr << "Graphical dynamic library (" << av[1] << ") does not exist or is not compatible." << std::endl;
            return 84;
        }
        init_t  *init_lib = (init_t*)dlsym(handle, "init");
        if (dlerror() != NULL)
            return 84;
        IDisplayModule  *display = init_lib();
        display->init();
        game = display->start(game);
        graph_lib = display->get_graph_lib();
        dlclose(handle);
        //printf("lib:%s\n", graph_lib.c_str());
        if (strcmp(graph_lib.c_str(), "") != 0) {
            av[1] = (char *)graph_lib.c_str();
            return (main(ac, av));
        }
    } else {
        printUsage();
        return 84;
    }
    return 0;
}