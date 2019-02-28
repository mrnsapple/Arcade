/*
** EPITECH PROJECT, 2019
** my puts
** File description:
** by oriol
*/

//#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "list.hpp"
//#include "get_next_line.h"

void    myputchar(char c)
{
    write(1, &c, 1);
}

extern "C" void  my_putstr(std::string str)
{
    std::cout << str;
    //return (0);
}

/*void    *malloc(size_t size)
{
    my_putstr("mallocstuf\n");
}
*/

#include <iostream>

extern "C" void hello() {
    std::cout << "hello" << '\n';
}