/*
** EPITECH PROJECT, 2019
** OOP
** File description:
** main
*/

#include <iostream>
#include <stdlib.h>
#include <dlfcn.h>
#include "IDisplayModule.hpp"

int main()
{
    void    *handle;

    handle = dlopen("./liblib.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return EXIT_FAILURE;
    }
    init_t  *init_lib = (init_t*)dlsym(handle, "init");
    if (!init_lib) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return EXIT_FAILURE;
    }
    IDisplayModule  *mod = init_lib();
    std::cout << mod->getName() << std::endl;
    dlclose(handle);
}