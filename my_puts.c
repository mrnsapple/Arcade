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
//#include "list.h"
//#include "get_next_line.h"

void    myputchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int i = 0;
    
    while (str != NULL && str[i] != '\0') {
        myputchar(str[i]);
        i++;
    }
    return (0);
}

int my_strlen(char *str)
{
    int i = 0;
    
    while (str != NULL && str[i] != '\0')
        i++;
    return (i);
}

void    *malloc(size_t size)
{
    my_putstr("mallocstuf\n");
}
