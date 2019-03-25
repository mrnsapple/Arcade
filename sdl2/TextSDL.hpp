/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** TextSDL
*/

#ifndef TEXTSDL_HPP_
#define TEXTSDL_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class TextSDL {
public:
    SDL_Renderer    *render;
    TTF_Font    *font;
    SDL_Color   color;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect    dstrect;

    TextSDL(SDL_Window *_win) {
        TTF_Init();
        render = SDL_CreateRenderer(_win, -1, 0);
        font = TTF_OpenFont("./assets/font.ttf", 25);
        color = {255, 0, 0};
    }
    
    void    setText(std::string str) {
        surface = TTF_RenderText_Solid(font, str.c_str(), color);
        texture = SDL_CreateTextureFromSurface(render, surface);
    }

    void    setSize(int width, int height) {
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
        dstrect.w = width;
        dstrect.h = height;
    }

    void    setPosition(int posX, int posY) {
        dstrect.x = posX;
        dstrect.y = posY;
    }
    
    void    draw() {
        SDL_RenderCopy(render, texture, NULL, &dstrect);
        SDL_RenderPresent(render);
    }
    ~TextSDL() {
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
        TTF_CloseFont(font);
        SDL_DestroyRenderer(render);
        TTF_Quit();
    }

protected:
private:
};

#endif /* !TEXTSDL_HPP_ */
