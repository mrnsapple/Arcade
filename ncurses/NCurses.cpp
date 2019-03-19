/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NCurses
*/

#include "NCurses.hpp"
#include <iostream>
#include <string>
#include <dlfcn.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

NCurses::NCurses() : _user_name("") , _key_press(0), _game(NULL)
{
}

NCurses::~NCurses()
{
}

void    NCurses::init()
{
    if ((stdscr = initscr()) == NULL )
        	exit(84);
	initscr();
}

void    NCurses::get_keypad_not_wait(void)
{
    noecho();
    nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
    _key_press = getch();
}
void    NCurses::set_direc(void)
{
    if (_key_press == KEY_UP)
        _game->set_dir('t');
    if (_key_press == KEY_DOWN)
        _game->set_dir('b');
    if (_key_press == KEY_LEFT)
        _game->set_dir('l'); 
    if (_key_press == KEY_RIGHT)
        _game->set_dir('r');   
}

void NCurses::get_keypad(void)
{
    noecho();
    keypad(stdscr, TRUE);
    _key_press = getch();
}

void    NCurses::print_map(void)
{
    std::vector<std::string> _map = _game->get_map();
    //std::vector<std::string> _number_map = _game->get_number_map();
    for (std::string a : _map) {
    
        wprintw(stdscr, a.c_str());
        wprintw(stdscr, "\n");
    }
    wprintw(stdscr, "Score: ");
    wprintw(stdscr, (std::to_string(_game->get_size() - 4)).c_str());
    wprintw(stdscr, "\n");
    /*for (std::string a : _number_map) {
        wprintw(stdscr, a.c_str());
        wprintw(stdscr, "\n");
    }*/
}

void    NCurses::specify_game(char *path_to_game)
{
    void *handler = dlopen(path_to_game, RTLD_LAZY);

    if (!handler)
       _game = NULL;
    else {
       init_g *init_game =   (init_g *)dlsym(handler, "init");
        _game = init_game();
        _game->init();
    }   
}

void       NCurses::get_game()
{
    std::string game_selected = "";
    std::string val;

    for (game_selected = "", _key_press = 0; _key_press != '\n';) {// _user_name = _user_name + _key_press)
        wprintw(stdscr, "Welcome ");
        wprintw(stdscr, _user_name.c_str());
        wprintw(stdscr, ".\n\nAvailable games:\n\tnibbler\n\tpacman\n\nChoose a game by writing it's name: ");
        wprintw(stdscr, game_selected.c_str());
        get_keypad();
        my_refresh();
        val = _key_press;
        if (_key_press != '\n')
            game_selected.append(val);
    }
    _game_name = game_selected;
    if (game_selected.compare("nibbler") == 0)
        specify_game((char *)"games/lib_arcade_nibbler.so");
    else if (game_selected.compare("pacman") == 0)
        specify_game((char *)"games/lib_arcade_pacman.so"); 
    else {
        init_pair(1, COLOR_RED, COLOR_BLACK);
	    attron(COLOR_PAIR(1));
        wprintw(stdscr, game_selected.c_str());
        wprintw(stdscr, " isn't a valid game name.\n\n");
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
	    attron(COLOR_PAIR(2));
        get_game();
    }
}

void    NCurses::get_name()
{
    std::string val;

    my_refresh();
    wprintw(stdscr, "Enter your name: ");
    for (_user_name = "", _key_press = 0; _key_press != '\n';) {// _user_name = _user_name + _key_press)
        get_keypad();
        my_refresh();
        val = _key_press;
        if (_key_press != '\n')
            _user_name.append(val);
        wprintw(stdscr, "Enter your name: ");
        wprintw(stdscr, _user_name.c_str());
    }
}

void    NCurses::my_refresh()
{
    refresh();
	clear();
	start_color();
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
    //init_pair(1, COLOR_RED, COLOR_BLACK);
	//attron(COLOR_PAIR(1));
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void    NCurses::start()
{
    get_name();
    my_refresh();
    get_game();
    if (_game == NULL) {
        wprintw(stdscr, "It's null\n");
       // stop();
    }
    wprintw(stdscr, "after it's null\n");
        get_keypad();

    for (int loop = 0; loop == 0;) {
        my_refresh();
        //if (_game_name.compare("nibbler") == 0)
        print_map();
        //delay(500000);                        
        get_keypad_not_wait();
        set_direc();
        sleep(1);
        //if (_game->play() == false)
        //    loop = 1;
    }
   this->stop(); 
}

void    NCurses::stop()
{
    endwin();
	//refresh();
    exit(0);
}

std::string NCurses::setUserName()
{
    return "Anon";
}