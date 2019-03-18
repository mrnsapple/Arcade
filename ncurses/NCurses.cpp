/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NCurses
*/

#include "NCurses.hpp"

NCurses::NCurses()
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
    refresh();
	clear();
	start_color();
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
    wprintw(stdscr, "ejejejejje\n");
    init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
}

void    NCurses::start()
{
    printf("In start\n");
    for (int loop = 0; loop == 0;) {
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
