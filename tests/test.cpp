/*
** EPITECH PROJECT, 2019
**  test 
** File description:
** by oriol
*/

#include <criterion/criterion.h>
#include "../string.h"

#include <iostream>
#include <string>
#include <dlfcn.h>
//#include "../IDisplayModule.hpp"
#include <string.h>

//string    *a;
const char    *b = "ulaula";



//string_init(a, b);
Test (dlopen, return_value)
{
    void    *handle = dlopen("lib/lib_arcade_ncurses.so", RTLD_LAZY);
    // if (!handle) {
    //     std::cerr << "Graphical dynamic library (" << av[1] << ") does not exist or is not compatible." << std::endl;
    //    return 84;
    // }
    cr_assert_eq(handle, NULL);
}
