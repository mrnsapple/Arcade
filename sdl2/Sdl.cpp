/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sdl
*/

#include "Sdl.hpp"

Sdl::Sdl() : _scene(USERINPUT), graphLib("")
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
    _render = SDL_CreateRenderer(_win, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    _intro = new TextSDL({255, 0, 0}, "Welcome ", {0, 0, 0, 0}, _render);
    _introInput = new TextSDL({255, 0, 0}, "", {100, 0, 0, 0}, _render);
    _libchoose = new TextSDL({255, 255, 255}, "Choose a graphical Library : ", {0, 50, 0, 0}, _render);
    _gamechoose = new TextSDL({255, 255, 255}, "Choose a game : ", {0, 100, 0, 0}, _render);
    std::vector<std::string> names = getLibName("./lib");
    for (std::vector<std::string>::iterator it = names.begin(); it != names.end(); ++it) {
        int i = ((it - names.begin()) + 1) * 10;
        _libOptions.push_back(new TextSDL({255, 255, 255}, *it, {0, 70 + (i * 2), 0, 0}, _render));
    }
    _libInput = new TextSDL({0, 255, 0}, "", {380, 50, 0, 0}, _render);
    names = getLibName("./games");
    for (std::vector<std::string>::iterator it = names.begin(); it != names.end(); ++it) {
        int i = ((it - names.begin()) + 1) * 10;
        _gameOptions.push_back(new TextSDL({255, 255, 255}, *it, {0, 120 + (i * 2), 0, 0}, _render));
    }
    _gameInput = new TextSDL({0, 0, 255}, "", {200, 100, 0, 0}, _render);
}

IGameModule*      Sdl::start(IGameModule *game)
{
    while (isClosed != true) {
        if (game == NULL) {
            while (SDL_PollEvent(&_event)) {
                stop();
                handleTextInput(USERINPUT, _introInput, {100, 0, 0, 0});
                handleTextInput(CHOOSELIB, _libInput, {380, 50, 0, 0});
                handleTextInput(CHOOSEGAME, _gameInput, {200, 100, 0, 0});
                handleKeyboardEvent();
                required_actions();
            }
            if (_scene == USERINPUT) {
                _intro->draw(_render);
                _introInput->draw(_render);
                SDL_StartTextInput();
            }
            if (_scene == CHOOSELIB) {
                _libchoose->draw(_render);
                _libInput->draw(_render);
                for (auto obj : _libOptions) {
                    obj->draw(_render);
                }
                SDL_StartTextInput();
            }
            if (_scene == CHOOSEGAME) {
                clear({0,0,0});
                _intro->draw(_render);
                _introInput->draw(_render);
                _libchoose->draw(_render);
                _libInput->draw(_render);
                _gamechoose->draw(_render);
                _gameInput->draw(_render);
                for (auto obj : _gameOptions) {
                    obj->draw(_render);
                }
                SDL_StartTextInput();
            }
            game_loop();
        }
        if (game != NULL) {
            _game = game;
            _scene = GAMEMODE;
            game_loop();
        }
        SDL_RenderPresent(_render);
    }
    return _game;
}

void    Sdl::clear(SDL_Color color)
{
    SDL_SetRenderDrawColor(_render, color.r, color.g, color.b, color.a);
    SDL_RenderClear(_render);
}

void    Sdl::handleTextInput(Sdl::scene _scen, TextSDL *text, SDL_Rect rect)
{
    if (_scene == _scen) {
        if (_event.type == SDL_TEXTINPUT) {
            text->_input += _event.text.text;
            text->set(text->_input, rect, _render);
        }
    }
}

void    Sdl::handleKeyboardEvent()
{
    if (_scene == USERINPUT) {
        if (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
            _scene = CHOOSELIB;
        }
    }
    if (_scene == CHOOSELIB) {
        if (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_RETURN && _libInput->_input != "") {
            _scene = CHOOSEGAME;
        }
    }
    if (_scene == CHOOSEGAME) {
        if (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_RETURN && _gameInput->_input != "") {
            void    *handle = dlopen("games/lib_arcade_nibbler.so", RTLD_LAZY);
            init_g  *init_game = (init_g*)dlsym(handle, "init");
            _game = init_game();
            _game->init();
            _scene = GAMEMODE;
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
    set_direc();
    return true;
}

void    Sdl::game_loop()
{
    if (_scene == GAMEMODE) {
        clear({0, 0, 0});
        loadMap();
        SDL_Delay(150);
        _game->set_game_time(loop);
        _game->play();
        loop++;
    }
}

void    Sdl::loadMap()
{
    std::vector<std::string>    map = _game->get_map();

    if (arrayMap.empty()) {
        for (std::vector<std::string>::iterator it = map.begin(); it != map.end(); ++it) {
            for (std::string::iterator c = it->begin(); c != it->end(); ++c) {
                int x = 25 * (c - it->begin());
                int y = 25 * (it - map.begin());
                if (*c == '#')
                    arrayMap.push_back(new RectSDL({255, 0, 0}, {x, y, 20, 20}));
                if (*c == '>')
                    arrayMap.push_back(new RectSDL({100, 0, 255}, {x, y, 20, 20}));
                if (*c == '<')
                    arrayMap.push_back(new RectSDL({0, 255, 255}, {x, y, 20, 20}));
                if (*c == '$')
                    arrayMap.push_back(new RectSDL({0, 255, 0}, {x, y, 20, 20}));
                
                if (*c == 'o')
                    arrayMap.push_back(new RectSDL({255, 255, 255}, {x, y, 20, 20}));                
                if (*c == 'C')
                    arrayMap.push_back(new RectSDL({255, 255, 0}, {x, y, 20, 20}));
            }
        }
    }
    for (auto rect : arrayMap) {
        rect->draw(_render);
    }
    std::stringstream   ss;
    ss << (_game->get_size() - 4);
    TextSDL score({255, 255, 255}, "score : " + ss.str(), {0, 400, 0, 0}, _render);
    std::stringstream   dd;
    dd << loop;
    TextSDL time({255, 255, 255}, "time : " + dd.str(), {0, 450, 0, 0}, _render);    
    score.draw(_render);
    time.draw(_render);
    arrayMap.clear();
}

void    Sdl::set_direc()
{
    if (_scene == GAMEMODE) {
        if (_event.type == SDL_KEYDOWN) {
            if (_event.key.keysym.scancode == SDL_SCANCODE_UP)
                _game->set_dir('t');
            if (_event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                _game->set_dir('b');
            if (_event.key.keysym.scancode == SDL_SCANCODE_LEFT)
                _game->set_dir('l');
            if (_event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                _game->set_dir('r');
        }
    }
}

void    Sdl::initialize_values()
{

}

std::string Sdl::get_graph_lib()
{
    return graphLib;
}

