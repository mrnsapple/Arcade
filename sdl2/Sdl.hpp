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
class Sdl : public IDisplayModule {
	public:
		Sdl();
		~Sdl();

        void init();
        IGameModule *   start(IGameModule *game);
        void stop();
        bool required_actions();
        void game_loop();
        void initialize_values();
        std::string get_graph_lib();

	protected:
        SDL_Window *_win;
        bool isClosed;
        SDL_Event _event;
	private:
};

extern "C" IDisplayModule *init() {
    return new Sdl;
}

#endif /* !SDL_HPP_ */
