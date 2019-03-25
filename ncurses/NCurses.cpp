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

NCurses::NCurses() : _user_name("") , _key_press(0), _game(NULL), _prev_library(-1), _graphic_lib("lib/lib_arcade_ncurses.so")
{
    _available_game["pacman"] = "games/lib_arcade_pacman.so";
    _available_game["nibbler"] = "games/lib_arcade_nibbler.so";
    //
    _available_game_names.push_back("pacman");
    _available_game_names.push_back("nibbler");
    //
    _print_info.push_back("Enter your name: ");
    _print_info.push_back("\n\nAvailable games:\n\tnibbler\n\tpacman\n\nChoose a game by writing it's name: ");
    _print_info.push_back("\n\nAvailable libraries:\n\tncurses\n\tsfml\n\nChoose a library by writing it's name: ");

}

NCurses::~NCurses()
{
}

void    NCurses::print_print_info(int pos, const char *content)
{
    unsigned int count = 0;

    for (std::string a : _print_info) {
        wprintw(stdscr, a.c_str());
        if (count == pos)
            wprintw(stdscr, content);
        count++;
    }
}


void    NCurses::NextLib()
{

}

void    NCurses::PrevLib()
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
    nodelay(stdscr, FALSE);

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

void    NCurses::inside_get_game()
{
    int count = 0;
    std::string my_current_game = "";

    for (std::string a : _available_game_names) {
        if (strcmp(a.c_str(), _game_name.c_str()) == 0) {//a.compare(_game_name) == 0); {
            my_current_game = _available_game[a];
            specify_game((char *)my_current_game.c_str());
            _prev_library = count;      
            break;
        }
        count++;
    }
    if (my_current_game.compare("") == 0) {
        init_pair(1, COLOR_RED, COLOR_BLACK);
	    attron(COLOR_PAIR(1));
        wprintw(stdscr, _game_name.c_str());
        wprintw(stdscr, " isn't a valid game name.\n\n");
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
	    attron(COLOR_PAIR(2));
        get_game();
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
        if (_key_press == 27) {// ESQ, exit
        this->stop();
        exit (0);
        }
        if (_key_press != '\n')
            game_selected.append(val);
    }
    _game_name = game_selected;
    inside_get_game();
    
}

void    NCurses::get_name()
{
    std::string val;

    my_refresh();
    print_print_info(-1, "");
    //wprintw(stdscr, "Enter your name: ");
    for (_user_name = "", _key_press = 0; _key_press != '\n';) {// _user_name = _user_name + _key_press)
        get_keypad();
        my_refresh();
        val = _key_press;
        if (_key_press == 27) {// ESQ, exit
           this->stop();
            exit (0);
        }
        if (_key_press != '\n')
            _user_name.append(val);
        print_print_info(0, _user_name.c_str());
        //wprintw(stdscr, "Enter your name: ");
       // wprintw(stdscr, _user_name.c_str());
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

void    NCurses::NextGame()
{
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void    NCurses::game_loop()
{
    for (int loop = 0; loop == 0;) {
        my_refresh();
        print_map();
        //wprintw(stdscr, "key:press:%d, %3d, %c\n",_key_press, _key_press, _key_press);
        //delay(500000);                        
        get_keypad_not_wait();
        set_direc();
        sleep(1);
        if (required_actions() == false)
           loop = 1;
        if(_game->play() == false ) {
            loop = 1;
            _graphic_lib = "";
        }
        
    }
}

void    NCurses::start()
{
    get_name();
    my_refresh();
    get_game();
    if (_game == NULL) {
        wprintw(stdscr, "It's null\n");
        stop();
        exit (84);
    }
    game_loop();
    
   this->stop(); 
   //exit (0);
}

void    NCurses::stop()
{
    endwin();
	//refresh();
}

std::string NCurses::setUserName()
{
    return "Anon";
}

bool    NCurses::required_actions()
{
    if (_key_press == 27) {// ESQ, exit
        this->stop();
        exit (0);
    }
    if (_key_press == 10) {// Enter, restart the game
        _game->init();
        this->game_loop();
    }   
    if (_key_press == 'p') {// Go to menu
        _game->initialize_values();
        initialize_values();
        this->start();
    }
    if (_key_press == 'z' || _key_press == 'x') { // Change game
        if (strcmp(_game_name.c_str(), "nibbler") == 0)
            _game_name = "pacman";
        else
            _game_name = "nibbler";
        inside_get_game();
    }
    if (_key_press == 'j' || _key_press == 'l') { // Change game
        if (strcmp(_graphic_lib.c_str(), "lib/lib_arcade_ncurses.so") == 0)
            _graphic_lib = "lib/lib_arcade_sfml.so";
        else if (strcmp(_graphic_lib.c_str(), "lib/lib_arcade_sfml.so") == 0)
            _graphic_lib = "lib/lib_arcade_ncurses.so";
        else
            _graphic_lib = "lib/lib_arcade_sfml.so";
        return false;
    }
    return true;
}

void NCurses::initialize_values()
{
    _key_press = 0;
    _user_name = "";
    _game = NULL;
    _game_name = "";
}

std::string NCurses::get_graph_lib()
{
    return _graphic_lib;
}