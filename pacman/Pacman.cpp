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

bool    its_not_character(std::vector<std::string> _map, int y, int x)
{
    std::string str = "#C$";

    for (auto a : str) {
        if (_map[y][x] == a)
            return false;
    }
    return true;
}

bool Pacman::move_ghost(int gost_y, int gost_x, int y, int x)
{
    // 0 is left, 1 is right, 2 is top, 3 is bot
    int random_val;
    srand(time(0) + gost_y + gost_x + y + x); 
    random_val = rand() % 4;
    if (random_val == 0 && its_not_character(_map, gost_y, gost_x - 1))
        _map[gost_y][gost_x - 1] = 'q';
    else if (random_val == 1 && its_not_character(_map, gost_y, gost_x + 1))
        _map[gost_y][gost_x + 1] = 'q';
    else if (random_val == 2 && its_not_character(_map, gost_y - 1, gost_x))
        _map[gost_y - 1][gost_x] = 'q';
    else if (random_val == 3 && its_not_character(_map, gost_y + 1, gost_x))
        _map[gost_y + 1][gost_x] = 'q';
    else
        return false;
    //move_ghost(gost_y, gost_x, y, x);
    return true;
}

void    Pacman::increase_numbers_map(int x, int y) // move the goast
{
    bool    delete_q = true;
    int num_ghosts = 0;
    int num_ques = 0;
    // ADD q in new ghost pos
    for (int gost_y = 0; gost_y < _map.size(); gost_y++)
        for (int gost_x = 0; gost_x < (_map[gost_y]).size(); gost_x++)
            if (delete_q  && _map[gost_y][gost_x] == '$')
                delete_q = move_ghost(gost_y, gost_x, y, x);
    // COUNT num q are same as $
    for (int gost_y = 0; !delete_q && gost_y < _map.size(); gost_y++)
        for (int gost_x = 0; gost_x < (_map[gost_y]).size(); gost_x++) {
            if (_map[gost_y][gost_x] == 'q')
                num_ques++;
            if (_map[gost_y][gost_x] == '$')
                num_ghosts++;
        }
    // Move ghost in q pos
    for (int y = 0; y < _map.size(); y++)
        for (int x = 0; x < (_map[y]).size(); x++) {
            if (num_ghosts == num_ques && _map[y][x] == '$')
                _map[y][x] = ' ';
            if (num_ghosts == num_ques && _map[y][x] == 'q')
                _map[y][x] = '$';
            if (num_ghosts != num_ques && _map[y][x] == 'q')
                _map[y][x] = ' ';
      
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
    increase_numbers_map(x, y);//for move ghosts
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