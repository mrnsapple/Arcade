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
    SDL_Quit();
}

void    Sdl::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _win = SDL_CreateWindow("Sdl - Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 820, 580, SDL_WINDOW_ALLOW_HIGHDPI);
    intro = new TextSDL(_win);
    intro->setText("Welcome ");
    intro->setPosition(0, 0);
    intro->setSize(0, 0);
}

IGameModule *      Sdl::start(IGameModule *game)
{
    while (isClosed != true) {
        intro->draw();
         while (SDL_PollEvent(&_event)) {
            stop();
        }
    }
    //menu con nombre, libreria y juego    
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
    return "";
}

