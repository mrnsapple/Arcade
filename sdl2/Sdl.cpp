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
    _win = SDL_CreateWindow("Sdl - Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 820, 580, SDL_WINDOW_ALLOW_HIGHDPI);
    // TTF_Init();
    TTF_Init();
    renderer = SDL_CreateRenderer(_win, -1, 0);
    font = TTF_OpenFont("./assets/font.ttf", 25);
    color = { 255, 255, 255};
    surface = TTF_RenderText_Solid(font, "Hello nibber", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture,NULL,NULL);
    SDL_RenderPresent(renderer);
}

void    Sdl::start()
{
    while (isClosed != true) {
         while (SDL_PollEvent(&_event)) {
            stop();
        }
    }
    //menu con nombre, libreria y juego    
}

void    Sdl::stop()
{
    if (_event.type == SDL_QUIT)
        TTF_Quit();
        TTF_CloseFont(font);
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
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

