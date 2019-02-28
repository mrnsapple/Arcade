/*
** EPITECH PROJECT, 2019
** main
** File description:
** by oriol
*/
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "list.hpp"

void  my_putstr(std::string str);

int main()
{
    void *handle;
    void (*func)(std::string str);
    std::string a = "damama";
    
    handle = dlopen("./liball.so", RTLD_LAZY);
    *(void**)(&func) = dlsym(handle, "my_putstr");
    func(a);
    // my_putstr("damama");
    dlclose(handle);
}
