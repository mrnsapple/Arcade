/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sdl
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include "../IDisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "TextSDL.hpp"
#include "RectSDL.hpp"
#include "../IGameModule.hpp"

class Sdl : public IDisplayModule {
public:
    Sdl();
    ~Sdl();

    enum scene {
        USERINPUT,
        CHOOSELIB,
        CHOOSEGAME,
        GAMEMODE
    };

    void init();
    IGameModule *   start(IGameModule *game);
    void stop();
    bool required_actions();
    void game_loop();
    void initialize_values();
    std::string get_graph_lib();

    void    handleTextInput(scene _scen, TextSDL *text, SDL_Rect rect);
    void    handleKeyboardEvent();
    void    clear(SDL_Color color);
    
    static bool endsWith(const std::string& str, const std::string& suffix) {
        return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
    }
        
    std::vector<std::string>    getLibName(std::string path) {
        std::vector<std::string>    vec;
        DIR *pdir = NULL;
        dirent  *pent = NULL;

        pdir = opendir(path.c_str());
        while (pent = readdir(pdir))
        if (endsWith(pent->d_name, ".so"))
            vec.push_back(pent->d_name);
        closedir(pdir);
        return vec;    
    }

    void    loadMap();
    void    set_direc();

protected:
    SDL_Window *_win;
    SDL_Renderer    *_render;
    SDL_Event _event;
    bool isClosed;
    scene   _scene;

    TextSDL *_intro;
    TextSDL *_introInput;

    TextSDL *_libchoose;
    TextSDL *_libInput;
    std::vector<TextSDL*>   _libOptions;

    TextSDL *_gamechoose;
    TextSDL *_gameInput;
    std::vector<TextSDL*>   _gameOptions;

    IGameModule *_game;
    std::vector<RectSDL*>   arrayMap;

    std::string graphLib;


private:
};

extern "C" IDisplayModule *init() {
    return new Sdl;
}

#endif /* !SDL_HPP_ */
