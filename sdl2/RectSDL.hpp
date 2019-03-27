/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** RectSDL
*/

#ifndef RECTSDL_HPP_
#define RECTSDL_HPP_

#include <SDL2/SDL.h>

class RectSDL {
public:
    SDL_Rect    r;
    SDL_Color   c;
    RectSDL(SDL_Color color, SDL_Rect rect) {
        r = rect;
        c = color;
    }
    void    draw(SDL_Renderer *render) {
        SDL_SetRenderDrawColor(render, c.r, c.g, c.b, c.a);
        SDL_RenderFillRect(render, &r);
    }
    ~RectSDL() {}

protected:
private:
};

#endif /* !RECTSDL_HPP_ */
