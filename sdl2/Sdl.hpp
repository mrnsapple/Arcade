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

class Sdl : public IDisplayModule {
	public:
		Sdl();
		~Sdl();

        enum scene {
            USERINPUT,
            CHOOSELIB,
            CHOOSEGAME
        };

        void init();
        IGameModule *   start(IGameModule *game);
        void stop();
        bool required_actions();
        void game_loop();
        void initialize_values();
        std::string get_graph_lib();

        void    handleTextInput();
        void    handleKeyboardEvent();
        void    clear(SDL_Color color);
        
	protected:
        SDL_Window *_win;
        bool isClosed;
        SDL_Event _event;

        SDL_Renderer    *_render;

        TextSDL *_intro;
        TextSDL *_textInput;
        TextSDL *_libchoose;
        TextSDL *_gamechoose;
        scene   _scene;
    
	private:
};

extern "C" IDisplayModule *init() {
    return new Sdl;
}

#endif /* !SDL_HPP_ */
