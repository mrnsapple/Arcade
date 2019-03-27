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
    std::string _str;
    std::string _input;

    TextSDL(SDL_Color color, std::string str, SDL_Rect rect, SDL_Renderer *render, int fontSize = 25) {
        _input = "";
        _color = color;
        set(str, rect, render, fontSize);
    }

    void    set(std::string str, SDL_Rect rect, SDL_Renderer *render, int fontSize = 25)
    {
        TTF_Init();
        font = TTF_OpenFont("./assets/font.ttf", fontSize);
        setText(str, render);
        setPosition(rect.x, rect.y);
        setSize(rect.w, rect.h);        
    }
    
    void    setText(std::string str, SDL_Renderer *render) {
        _str = str;
        surface = TTF_RenderText_Solid(font, _str.c_str(), _color);
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
    }

    void    update(SDL_Renderer *render, std::string str = "") {
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
        surface = TTF_RenderText_Solid(font, str.c_str(), _color);
        texture = SDL_CreateTextureFromSurface(render, surface);
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
