/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sdl
*/

#include "Sdl.hpp"

Sdl::Sdl()
{
}

Sdl::~Sdl()
{
    SDL_DestroyWindow(_win);
    SDL_Quit();
}

void    Sdl::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _win = SDL_CreateWindow("Sdl - Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 820, 580, SDL_WINDOW_OPENGL);
}

void    Sdl::start()
{
    while (isClosed != true) {
         while (SDL_PollEvent(&_event)) {
            stop();
        }
    }    
}

void    Sdl::stop()
{
    if (_event.type == SDL_QUIT)
        isClosed = true;
}

bool    Sdl::required_actions()
{
    return false;
}

void    Sdl::game_loop()
{

}

void    Sdl::initialize_values()
{

}

std::string Sdl::get_graph_lib()
{
    return "Yes";
}
