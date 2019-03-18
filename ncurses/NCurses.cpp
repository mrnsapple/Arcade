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

NCurses::NCurses() : _user_name("") , _key_press(0), _game(NULL)
{
}

NCurses::~NCurses()
{
}

void    NCurses::init()
{
    printf("In init\n");
    if ((stdscr = initscr()) == NULL )
        	exit(84);
	initscr();
}

void NCurses::get_keypad(void)
{
    noecho();
	keypad(stdscr, TRUE);
    _key_press = getch();
}

void    NCurses::print_map(void)
{
    wprintw(stdscr, "ejejejejje\n");
    
}

void       NCurses::get_game()
{
    void *handler = dlopen("../games/lib_arcade_nibbler.so", RTLD_LAZY);

    if (!handler)
       _game = NULL;
    else {
       init_g *init_game =   (init_g *)dlsym(handler, "init");
        _game = init_game();
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
    my_refresh();
    wprintw(stdscr, "Welcome ");
    wprintw(stdscr, _user_name.c_str());
    get_keypad();
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

void    NCurses::start()
{
    //get_name();
        my_refresh();

    get_game();
  if (_game != NULL) {
       wprintw(stdscr, "It's nil\n");
     _game->play();
  }
    else
        wprintw(stdscr, "It's null\n");
    get_keypad();
  
    for (int loop = 0; loop == 0;) {
        my_refresh();
        print_map();
        get_keypad();
        if (_key_press == KEY_UP)
            loop = 1;
    }
   this->stop(); 
}

void    NCurses::stop()
{
    endwin();
	//refresh();
    exit (0);
}
std::string NCurses::setUserName()
{
    return "Anon";
}