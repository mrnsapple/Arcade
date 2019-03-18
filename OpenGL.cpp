/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** OpenGL
*/

#include "OpenGL.hpp"

OpenGL::OpenGL()
{
}

OpenGL::~OpenGL()
{
    SDL_GL_DeleteContext(_glContext);
    SDL_DestroyWindow(_win);
    SDL_Quit();
}

void    OpenGL::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 64);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    _win = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 820, 580, SDL_WINDOW_OPENGL);
    _glContext = SDL_GL_CreateContext(_win);
}

void    OpenGL::start()
{
    while (isClosed != true) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(_win);
        while (SDL_PollEvent(&_event)) {
            stop();
        }
    }
}

void    OpenGL::stop()
{
    if (_event.type == SDL_QUIT)
        isClosed = true;
}

std::string    OpenGL::setUserName()
{
    return "Anon";
}

