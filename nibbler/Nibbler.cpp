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
    _dir = 'l';
    _size = 4;
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
        //for (int i = 5; i < 8; i++)
        //    _map[_map[0].size()/2][i] = '>';
        //_map[_map[0].size()/2][4] = '<';
        myfile.close();
    }
    else
        _map.push_back("Not work\n");
}

std::vector<std::string> Nibbler::get_map()
{
    return _map;
}


void    Nibbler::move_top(int x, int y)
{
    for (int i = y - 1; i <= y + 1 - _size; i++) {
        _map[i][x] = _map[i + 1][x];
    }
}

void    Nibbler::move_bot(int x, int y)
{
    for (int i = y + 1; i >= y + 1 - _size; i--) {
        _map[i][x] = _map[i - 1][x];
    }
}

void    Nibbler::move_left(int x, int y)
{ 
    for (int i = x - 1; i <= x - 1 + _size; i++) {
        _map[y][i] = _map[y][i + 1];
    }
}

void    Nibbler::move_rigth(int x, int y)
{
    for (int i = x + 1; i >= x + 1 - _size; i--) {
        _map[y][i] = _map[y][i -1];
    }
}

bool    Nibbler::know_head(int x, int y)
{
    if (_dir == 'l') {
        if (_map[y][x - 1] != '#')
            move_left(x, y);
        else
            return false;
    }
    if (_dir == 'r') {
        if (_map[y][x + 1] != '#')
            move_rigth(x, y);
        else
            return false;
    }
    if (_dir == 'b') {
        if (_map[y - 1][x] != '#')
            move_bot(x, y);
        else
            return false;
    }
    if (_dir == 't') {
        if (_map[y + 1][x] != '#')
            move_top(x, y);
        else
            return false;
    } 
    return true; 
}

bool    Nibbler::play(void)
{
    for (int y = 0; y < _map.size(); y++)
        for (int x = 0; x < (_map[y]).size(); x++) {
            if (_map[y][x] == '<')
                return (know_head(x, y));
        }
    // wprintw(stdscr, "In nibler\n");
    std::cout << "TIME TO PLAY" << std::endl;
    return true;
}