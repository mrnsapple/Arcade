/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** OpenGL
*/

#ifndef OPENGL_HPP_
#define OPENGL_HPP_

#include "../IDisplayModule.hpp"
#include <SDL2/SDL.h>
#include <GL/glew.h>

class OpenGL : public IDisplayModule {
public:
    OpenGL();
    ~OpenGL();

    void    init();
    void    start();
    void    stop();
    void    NextLib();

    std::string setUserName();

protected:
    SDL_Window  *_win;
    SDL_GLContext   _glContext;
    bool    isClosed;
    SDL_Event   _event;
private:
};

extern "C" IDisplayModule *init() {
    return new OpenGL;
}

#endif /* !OPENGL_HPP_ */
