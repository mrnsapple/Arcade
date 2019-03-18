/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include "../list.hpp"

Nibbler::Nibbler()
{
    hasInit = false;
}

Nibbler::~Nibbler()
{
}

char *Nibbler::test()
{
    return ((char *)"test\n");
}

void    Nibbler::init()
{
    std::string line;
    std::ifstream myfile ("nibbler/map.txt");

    if (myfile.is_open()) {
        while ( std::getline (myfile,line) ) {
            _map.push_back(line);
        }
        myfile.close();
    }

    else
        _map.push_back("Not work\n");
}

std::vector<std::string> Nibbler::get_map()
{
    return _map;
}

void    Nibbler::play()
{
    // wprintw(stdscr, "In nibler\n");
    std::cout << "TIME TO PLAY" << std::endl;
}