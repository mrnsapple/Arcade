/*
** EPITECH PROJECT, 2019
** Pacman
** File description:
** byoriol
*/

#include "Pacman.hpp"
#include "../list.hpp"

Pacman::Pacman()
{
    hasInit = false;
    _dir = 't';
    _size = 4;
}

Pacman::~Pacman()
{
}

char *Pacman::test()
{
    return ((char *)"test\n");
}

void    Pacman::init()
{
    std::string line;
    std::ifstream myfile ("pacman/map.txt");

    if (myfile.is_open()) {
        while ( std::getline (myfile,line) ) {
            _map.push_back(line);
        }
        myfile.close();
    }
    else
        _map.push_back("Not work\n");
}

std::vector<std::string> Pacman::get_map()
{
    return _map;
}


std::vector<std::string> Pacman::get_number_map()
{
    return _number_map;
}


void    Pacman::move_top(int x, int y)
{ 
    if (_map[y - 1][x] == 'o')
        _size++;
    
    _map[y - 1][x] = 'C';
    _map[y][x] = ' ';
}
int     Pacman::get_size(void)
{
    return _size;
}

void    Pacman::move_bot(int x, int y)
{
    if (_map[y + 1][x] == 'o')
        _size++;
    
    _map[y + 1][x] = 'C';
    _map[y][x] = ' ';
}
void Pacman::move_ghost()
{}
void    Pacman::increase_numbers_map(int x, int y) // move the goast
{
    int gost_pos_x;
    int gost_pos_y;

    for (int y = 0; y < _map.size(); y++)
        for (int x = 0; x < (_map[y]).size(); x++)
            if (_map[y][x] == '$') {
              //  C_pos.push_bach(y);
              //  C_pos.push_bach(x); 
            }
         
}

void    Pacman::number_map_to_map()
{
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

void    Pacman::move_left(int x, int y)
{ 
    if (_map[y][x - 1] == 'o')
        _size++;
    _map[y][x - 1] = 'C';
    _map[y][x] = ' ';
}

void Pacman::set_dir(char dir)
{
    _dir = dir;
}

void    Pacman::move_rigth(int x, int y)
{
    if (_map[y][x + 1] == 'o')
        _size++;
    
    _map[y][x + 1] = 'C';
    _map[y][x] = ' ';
}

bool    Pacman::know_head(int x, int y)
{
    increase_numbers_map(x, y);
   if (_dir == 'l') {
        if (_map[y][x - 1] != '#' && _map[y][x - 1] != '$')
            move_left(x, y);
        else if (_map[y][x - 1] == '$')
            return false;
        else
            return true;
    }
   if (_dir == 'r') {
        if (_map[y][x + 1] != '#' && _map[y][x + 1] != '$')
            move_rigth(x, y);
        else if (_map[y][x + 1] == '$')
            return false;
        else
            return true;
        
    }
    if (_dir == 'b') {
        if (_map[y + 1][x] != '#' && _map[y + 1][x] != '$')
            move_bot(x, y);
        else if (_map[y + 1][x] == '$')
            return false;
        else
            return true;
    }
    if (_dir == 't') {
        if (_map[y - 1][x] != '#' && _map[y - 1][x] != '$')
            move_top(x, y);
        else if (_map[y - 1][x] == '$')
            return false;
        else
            return true;
    } 
    return true; 
}

bool    Pacman::play(void)
{
    for (int y = 0; y < _map.size(); y++)
        for (int x = 0; x < (_map[y]).size(); x++) {
            if (_map[y][x] == 'C')
                return (know_head(x, y));
        }
    // wprintw(stdscr, "In nibler\n");
    std::cout << "TIME TO PLAY" << std::endl;
    return true;
}