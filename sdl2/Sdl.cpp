/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sdl
*/

#include "Sdl.hpp"

Sdl::Sdl() : _scene(USERINPUT)
{
}

Sdl::~Sdl()
{
    SDL_DestroyWindow(_win);
    SDL_DestroyRenderer(_render);
    SDL_Quit();
}

void    Sdl::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _win = SDL_CreateWindow("Sdl - Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 820, 580, SDL_WINDOW_ALLOW_HIGHDPI);
    _render = SDL_CreateRenderer(_win, -1, 0);
    _intro = new TextSDL(_win, {255, 0, 0}, "Welcome ", {0, 0, 0, 0}, _render);
    _textInput = new TextSDL(_win, {255, 0, 0}, " [INPUT HERE] ", {100, 0, 0, 0}, _render);
    _libchoose = new TextSDL(_win, {255, 255, 255}, "Choose a graphical Library : ", {0, 50, 0, 0}, _render);
    _gamechoose = new TextSDL(_win, {255, 255, 255}, "Choose a game : ", {0, 100, 0, 0}, _render);
}

IGameModule*      Sdl::start(IGameModule *game)
{
    while (isClosed != true) {
        while (SDL_PollEvent(&_event)) {
            stop();
            handleTextInput();
            handleKeyboardEvent();
        }
        if (_scene == USERINPUT) {
            _intro->draw(_render);
            _textInput->draw(_render);
            SDL_StartTextInput();
        }
        if (_scene == CHOOSELIB) {
            _libchoose->draw(_render);
        }
        if (_scene == CHOOSEGAME) {
            _gamechoose->draw(_render);
        }
    }
}

void    Sdl::clear(SDL_Color color)
{
    SDL_SetRenderDrawColor(_render, color.r, color.g, color.b, color.a);
    SDL_RenderClear(_render);
}

void    Sdl::handleTextInput()
{
    if (_scene == USERINPUT)
        if (_event.type == SDL_TEXTINPUT) {
            std::cout << "Text Input -> " << _event.text.text << std::endl;
            // text += _event.text.text;
            // std::cout << "Total Text " << text << std::endl;
            // SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
            // SDL_RenderClear(intro->render);
            _textInput->setText("dooo", _render);
        }
}

void    Sdl::handleKeyboardEvent()
{
    if (_scene == USERINPUT) {
        if (_event.type == SDL_KEYDOWN && _event.key.keysym.scancode == SDL_SCANCODE_RETURN)
            SDL_StopTextInput();
        if (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_RETURN)
            _scene = CHOOSELIB;
    }
    if (_scene == CHOOSELIB) {
        if (_event.type == SDL_KEYDOWN && _event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
            _scene = CHOOSEGAME;
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
    return "";
}

