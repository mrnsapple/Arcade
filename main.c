/*
** EPITECH PROJECT, 2019
** main
** File description:
** by oriol
*/
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
void my_putstr(char *str);

int main()
{
    void *handle;
    void (*func)(char *str);
    
    
    handle = dlopen("./liball.so", RTLD_LAZY);
    *(void**)(&func) = dlsym(handle, "my_putstr");
    func("damama");
    // my_putstr("damama");
    dlclose(handle);
}
