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
        
        myfile.close();
        for (std::string a : _map) {
            _number_map.push_back(a);
        }
        for (int i = 5; i < 8; i++) {
            _map[_map[0].size()/2][i] = '>';
            _number_map[_map[0].size()/2][i] = i - 3 + '0';
        }
        _map[_map[0].size()/2][4] = '<';
        _number_map[_map[0].size()/2][4] = 1 + '0';
        
    }
    else
        _map.push_back("Not work\n");
}

std::vector<std::string> Nibbler::get_map()
{
    return _map;
}


std::vector<std::string> Nibbler::get_number_map()
{
    return _number_map;
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
    for (int y = 0; y < _number_map.size(); y++)
        for (int x = 0; x < (_number_map[y]).size(); x++) {
            if (_number_map[y][x] == _size + '0')
                _number_map[y][x] = ' ';
            else if (_number_map[y][x] > '0')
                _number_map[y][x] += 1;
        }
    _number_map[y][x - 1] = '1';
    for (int y = 0; y < _number_map.size(); y++)
        for (int x = 0; x < (_number_map[y]).size(); x++) {
            if (_number_map[y][x] == '1')
                _map[y][x] = '<';
            else if (_number_map[y][x] > '1')
                _map[y][x] = '>';
            else
                _map[y][x] = _number_map[y][x];     
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
            if (_map[y][x] == '<' && _number_map[y][x] != '1')
                return false;
            if (_map[y][x] == '<')
                return (know_head(x, y));
        }
    // wprintw(stdscr, "In nibler\n");
    std::cout << "TIME TO PLAY" << std::endl;
    return true;
}