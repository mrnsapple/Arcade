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
    TTF_Font    *font;
    SDL_Color   _color;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect    dstrect;

    TextSDL(SDL_Window *_win, SDL_Color color, std::string str, SDL_Rect rect, SDL_Renderer *render) {
        TTF_Init();
        font = TTF_OpenFont("./assets/font.ttf", 25);
        _color = color;
        setText(str, render);
        setPosition(rect.x, rect.y);
        setSize(rect.w, rect.h);
    }
    
    void    setText(std::string str, SDL_Renderer *render) {
        surface = TTF_RenderText_Solid(font, str.c_str(), _color);
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
    
    void    draw(SDL_Renderer *render) {
        SDL_RenderCopy(render, texture, NULL, &dstrect);
        SDL_RenderPresent(render);
    }
    ~TextSDL() {
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
        TTF_CloseFont(font);
        TTF_Quit();
    }

protected:
private:
};

#endif /* !TEXTSDL_HPP_ */
