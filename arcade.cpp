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

void    printUsage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t   ./arcade lib" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\t   lib\tgraphical dynamic library (e.j. lib_arcade_sfml.so)" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        void    *handle = dlopen(av[1], RTLD_LAZY);
        if (!handle)
            return 84;
        init_t  *init_lib = (init_t*)dlsym(handle, "init");
        IDisplayModule  *display = init_lib();
        display->init();
        dlclose(handle);
    } else {
        printUsage();
        return 84;
    }
    return 0;
}