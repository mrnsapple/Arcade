/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sdl
*/

#include "Sdl.hpp"

Sdl::Sdl() : _scene(USERINPUT), graphLib(""), isClosed(false), gameStatus(true)
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
    _gamechoose = new TextSDL({255, 255, 255}, "Choose game : ", {0, 100, 0, 0}, _render);
    libNames = getLibName("./lib");
    for (std::vector<std::string>::iterator it = libNames.begin(); it != libNames.end(); ++it) {
        int i = ((it - libNames.begin()) + 1) * 10;
        _libOptions.push_back(new TextSDL({255, 255, 255}, *it, {0, 70 + (i * 2), 0, 0}, _render));
    }
    _libInput = new TextSDL({0, 255, 0}, "", {380, 50, 0, 0}, _render);
    gameNames = getLibName("./games");
    for (std::vector<std::string>::iterator it = gameNames.begin(); it != gameNames.end(); ++it) {
        int i = ((it - gameNames.begin()) + 1) * 10;
        _gameOptions.push_back(new TextSDL({255, 255, 255}, *it, {0, 120 + (i * 2), 0, 0}, _render));
    }
    _gameInput = new TextSDL({0, 0, 255}, "", {180, 100, 0, 0}, _render);
    std::ifstream   file("scores.txt");
    std::string str;
    if (file.is_open()) {
        for (int i = 0; std::getline(file, str); i++) {
            int o = 25 * (i + 1);
            _scores.push_back(new TextSDL({255,255,255}, str, {300, o, 0, 0}, _render, 20));
        }
        file.close();
    }
}

IGameModule*      Sdl::start(IGameModule *game)
{
    while (isClosed != true) {
        handleEvents();
        if (game == NULL) {
            if (_scene == USERINPUT) {
                clear({0,0,0});
                _intro->draw(_render);
                _introInput->draw(_render);
                SDL_StartTextInput();
            }
            if (_scene == CHOOSELIB) {
                clear({0,0,0});
                _intro->draw(_render);
                _introInput->draw(_render);
                _libchoose->draw(_render);
                _libInput->draw(_render);
                for (auto obj : _libOptions)
                    obj->draw(_render);
                SDL_StartTextInput();
            }
            if (_scene == CHOOSEGAME) {
                clear({0,0,0});
                _intro->draw(_render);
                _introInput->draw(_render);
                _libInput->set(_libInput->_input, {0, 50, 0, 0}, _render);
                _libInput->draw(_render);
                _gamechoose->draw(_render);
                _gameInput->draw(_render);
                for (auto obj : _gameOptions)
                    obj->draw(_render);
                TextSDL scoreTitle({255,255,255}, "Scores", {300, 0, 0, 0}, _render);
                scoreTitle.draw(_render);
                for (auto obj : _scores)
                    obj->draw(_render);
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

void    Sdl::handleEvents()
{
    while (SDL_PollEvent(&_event)) {
        required_actions();
        stop();
        handleTextInput(USERINPUT, _introInput, {100, 0, 0, 0});
        handleTextInput(CHOOSELIB, _libInput, {380, 50, 0, 0});
        handleTextInput(CHOOSEGAME, _gameInput, {180, 100, 0, 0});
        handleKeyboardEvent();
    }
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
            if (_introInput->_input == "") {
                _introInput->set("Please fill the input", {100, 0, 0, 0}, _render);
                _introInput->_input = "";
            }
            else
                _scene = CHOOSELIB;
        }
    }
    handleChooseLibEvents();
    handleChooseGameEvents();
    
}

void    Sdl::handleChooseLibEvents()
{
    if (_scene == CHOOSELIB) {
        if (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_RETURN && _libInput->_input != "") {
            if (_libInput->_input == "sdl2")
                _scene = CHOOSEGAME;
            else {
                std::string lib = "lib/lib_arcade_" + _libInput->_input + ".so";
                void    *handle = dlopen(lib.c_str(), RTLD_LAZY);
                if (!handle) {
                    _libInput->set("ERROR TRY AGAIN", {380, 50, 0, 0}, _render);
                    _libInput->_input = "";
                } else {
                    graphLib = lib;
                    isClosed = true;
                    SDL_Quit();
                }
            }
        }
    }
}

void    Sdl::handleChooseGameEvents()
{
    if (_scene == CHOOSEGAME) {
        if (_event.type == SDL_KEYUP) {
            if (_event.key.keysym.scancode == SDL_SCANCODE_RETURN && _gameInput->_input != "") {
                std::string lib = "games/lib_arcade_" + _gameInput->_input + ".so";
                void    *handle = dlopen(lib.c_str(), RTLD_LAZY);
                if (!handle) {
                    _gameInput->set("ERROR!!!", {180, 100, 0, 0}, _render);
                    _gameInput->_input = "";
                } else {
                    init_g  *init_game = (init_g*)dlsym(handle, "init");
                    _game = init_game();
                    _game->init();
                    _scene = GAMEMODE;
                }
            }
        }
    }
}

void    Sdl::stop()
{
    if (_event.type == SDL_QUIT || (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
        isClosed = true;
}

bool    Sdl::required_actions()
{
    if (_scene == GAMEMODE) {
        RestartGame();
        NextLib();
        PrevLib();
        NextGame();
        PrevGame();
        set_direc();
    }
    return true;
}

void    Sdl::game_loop()
{
    if (_scene == GAMEMODE) {
        SDL_Delay(175);
        clear({0, 0 , 0});
        loadMap();
        if (gameStatus == false) {
            SDL_Delay(0);
            std::ofstream   file("scores.txt", std::fstream::app);
            if (file.is_open()) {
                file << _introInput->_input << " " << (_game->get_size() - 4) << "\n";
                file.close();
            }
            isClosed = true;
            SDL_Quit();
        }
        gameStatus = _game->play();
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
        
                if (*c == '!')
                    arrayMap.push_back(new RectSDL({128,0,128}, {x, y, 20, 20}));
                if (*c == 'o')
                    arrayMap.push_back(new RectSDL({255, 255, 255}, {x, y, 20, 20}));                
                if (*c == 'O')
                    arrayMap.push_back(new RectSDL({255,165,0}, {x, y, 20, 20}));
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
    TextSDL score({255, 255, 255}, "Score : " + ss.str(), {0, 400, 0, 0}, _render);
    std::stringstream   dd;
    dd << _game->get_game_time();
    TextSDL time({255, 255, 255}, "Time : " + dd.str(), {0, 450, 0, 0}, _render);    
    score.draw(_render);
    time.draw(_render);
    arrayMap.clear();
}

void    Sdl::set_direc()
{
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
    if (_event.type == SDL_KEYUP) {    
        if (_event.key.keysym.scancode == SDL_SCANCODE_Q) {
            _gameInput->_input = "";
            _scene = CHOOSEGAME;
        }
    }
}

void    Sdl::NextGame()
{
    if (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_X) {
        auto it = std::find(gameNames.begin(), gameNames.end(), _gameInput->_input);
        int num = std::distance(gameNames.begin(), it);
        num += 1;
        if (num > gameNames.size() - 1)
            num = 0;
        std::string lib = "games/lib_arcade_" + gameNames[num] + ".so";
        void    *handle = dlopen(lib.c_str(), RTLD_LAZY);
        init_g  *init_game = (init_g*)dlsym(handle, "init");
        _game = init_game();
        _gameInput->_input = gameNames[num];
        _game->init();
    }
}

void    Sdl::PrevGame()
{
    if (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_Z) {
        auto it = std::find(gameNames.begin(), gameNames.end(), _gameInput->_input);
        int num = std::distance(gameNames.begin(), it);
        num -= 1;
        if (num > 0)
            num = gameNames.size() - 1;
        std::string lib = "games/lib_arcade_" + gameNames[num] + ".so";
        void    *handle = dlopen(lib.c_str(), RTLD_LAZY);
        init_g  *init_game = (init_g*)dlsym(handle, "init");
        _game = init_game();
        _gameInput->_input = gameNames[num];
        _game->init();
    }
}

void    Sdl::NextLib()
{
    if (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_L) {
        auto it = std::find(libNames.begin(), libNames.end(), "sdl2");
        int num = std::distance(libNames.begin(), it);
        num += 1;
        if (num > libNames.size() - 1)
            num = 0;
        std::string lib = "lib/lib_arcade_" + libNames[num] + ".so";
        graphLib = lib;
        isClosed = true;
        SDL_Quit();
    }
}

void    Sdl::PrevLib()
{
    if (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_J) {
        auto it = std::find(libNames.begin(), libNames.end(), "sdl2");
        int num = std::distance(libNames.begin(), it);
        num -= 1;
        if (num > 0)
            num = libNames.size() - 1;
        std::string lib = "lib/lib_arcade_" + libNames[num] + ".so";
        graphLib = lib;
        isClosed = true;
        SDL_Quit();
    }
}

void    Sdl::RestartGame()
{
    if (_event.type == SDL_KEYUP && _event.key.keysym.scancode == SDL_SCANCODE_R) {
        _game->init();
    }
}

std::string Sdl::get_graph_lib()
{
    return graphLib;
}

