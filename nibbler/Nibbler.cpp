/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
{
    _dir = 'l';
    _size = 4;
    _game_time = 0;
}

Nibbler::~Nibbler()
{
}

bool Nibbler::move_ghost(int gost_y, int gost_x, int y, int x)
{
}

char *Nibbler::test()
{
    return ((char *)"test\n");
}

void    Nibbler::initialize_values()
{
    // INITIALIZE VAR
    _map.clear();
    _number_map.clear();
    _dir = 'l';
    _size = 4;

    // END INITIALIZE VAR
}

void    Nibbler::init()
{
    std::string line;
    std::ifstream myfile ("nibbler/map.txt");
    
    initialize_values();
    if (myfile.is_open()) {
        while ( std::getline (myfile,line) )
            _map.push_back(line);
        myfile.close();
        for (std::string a : _map)
            _number_map.push_back(a);
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
    increase_numbers_map(x, y - 1, '$');
    _number_map[y - 1][x] = '1';
    number_map_to_map();
}
int     Nibbler::get_size(void)
{
    return _size;
}

void    Nibbler::move_bot(int x, int y)
{
    increase_numbers_map(x, y + 1, '$');
    _number_map[y + 1][x] = '1';
    number_map_to_map();
}

std::vector<std::string> move_number_map(std::vector<std::string> _number_map)
{
    static int count = 0;
    int random_val_x;
    int random_val_y;

    count++;
    srand(time(0) * count); 
    random_val_y = rand() % _number_map.size() - 2;
    srand(time(0) + 300 * count); 
    random_val_x = rand() % (_number_map[0]).size() - 2;
    if (random_val_x > 11 || random_val_x < 1 || random_val_y > 11 || random_val_y < 1)
        return (move_number_map(_number_map));
    if (_number_map[random_val_y][random_val_x] == ' ')
        _number_map[random_val_y][random_val_x] = '$';
    else
        return (move_number_map(_number_map));
    return _number_map;
}

void    Nibbler::increase_numbers_map(int x, int y, char dol)
{
    int eat = 0;
    
    if (_number_map[y][x] == '$')
        eat = 1;
    for (int y = 0; y < _number_map.size(); y++)
        for (int x = 0; x < (_number_map[y]).size(); x++) {
            if (_number_map[y][x] == _size + '0' && eat == 1) {
                _size++;
                _number_map[y][x] == _size + '0';
            }
            else if(_number_map[y][x] == _size + '0')
                _number_map[y][x] = ' ';
            else if (_number_map[y][x] > '0')
                _number_map[y][x] += 1;
        }
    if (eat == 1)
        _number_map = move_number_map(_number_map);
}

void    Nibbler::number_map_to_map()
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

void    Nibbler::move_left(int x, int y)
{ 
    increase_numbers_map(x - 1, y, '$');
    _number_map[y][x - 1] = '1';
    number_map_to_map();
}

void Nibbler::set_dir(char dir)
{
    _dir = dir;
}

void    Nibbler::move_rigth(int x, int y)
{
    increase_numbers_map(x + 1, y, '$');
    _number_map[y][x + 1] = '1';
    number_map_to_map();}

bool    Nibbler::know_head(int x, int y)
{
    if (_dir == 'l') {
        if (_map[y][x - 1] != '#' && _map[y][x - 1] != '>')
            move_left(x, y);
        else
            return false;//else if (_map[y][x - 1] == '>')
        //    return true;
        
    }
    if (_dir == 'r') {
        if (_map[y][x + 1] != '#' && _map[y][x + 1] != '>')
            move_rigth(x, y);
        else
            return false;  //else if (_map[y][x + 1] == '>')
        //    return true;
        
    }
    if (_dir == 'b') {
        if (_map[y + 1][x] != '#' && _map[y + 1][x] != '>')
            move_bot(x, y);
        else
            return false;//else if (_map[y + 1][x] == '>')
        //    return true;
    }
    if (_dir == 't') {
        if (_map[y - 1][x] != '#' && _map[y - 1][x] != '>')
            move_top(x, y);
        else
            return false;//else if (_map[y - 1][x] == '>')
        //    return true;
    } 
    return true; 
}

bool    Nibbler::play(void)
{
    _game_time++;
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

int    Nibbler::get_game_time()
{
    return (_game_time);// = time;
}