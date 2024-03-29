/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml
*/

#include "Sfml.hpp"

Sfml::Sfml() : _scenario(USERINPUT), graphLib(""), _gameLib("")
{
}

Sfml::~Sfml()
{
}

bool    Sfml::required_actions()
{
    NextLib();
    PrevLib();
    restartGame();
    NextGame();
    PrevGame();
    set_direc();
    return true;
}

void    Sfml::restartGame()
{
    if (_scenario == GAMEMODE) {
        if (_event.type == sf::Event::KeyPressed &&_event.key.code == sf::Keyboard::R)
            game->init();
    }
}

void    Sfml::NextGame()
{
    if (_scenario == GAMEMODE) {
        if (_event.type == sf::Event::KeyPressed &&_event.key.code == sf::Keyboard::X) {
            auto it = std::find(libGame->libName.begin(), libGame->libName.end(), _gameLib);
            int num = std::distance(libGame->libName.begin(), it);
            num += 1;
            if (num > libGame->libName.size() - 1)
                num = 0;
            std::string lib = "games/" + libGame->libName[num];
            void    *handle = dlopen(lib.c_str(), RTLD_LAZY);
            init_g  *init_game = (init_g*)dlsym(handle, "init");
            game = init_game();
            _gameLib = lib.substr(lib.find("/") + 1);
            game->init();
        }
    }
}

void    Sfml::PrevGame()
{
    if (_scenario == GAMEMODE) {
        if (_event.type == sf::Event::KeyPressed &&_event.key.code == sf::Keyboard::Z) {
            auto it = std::find(libGame->libName.begin(), libGame->libName.end(), _gameLib);
            int num = std::distance(libGame->libName.begin(), it);
            num -= 1;
            if (num < 0)           
                num = libGame->libName.size() - 1;
            std::string lib = "games/" + libGame->libName[num];
            void    *handle = dlopen(lib.c_str(), RTLD_LAZY);
            init_g  *init_game = (init_g*)dlsym(handle, "init");
            game = init_game();
            _gameLib = lib.substr(lib.find("/") + 1);
            game->init();      
        }
    }
}

void    Sfml::NextLib()
{
    if (_scenario != USERINPUT) {
        if (_event.type == sf::Event::KeyPressed &&_event.key.code == sf::Keyboard::L) {
            auto it = std::find(libMenu->libName.begin(), libMenu->libName.end(), "lib_arcade_sfml.so");
            int num = std::distance(libMenu->libName.begin(), it);
            num += 1;
            if (num > libMenu->libName.size() - 1)
                num = 0;
            std::string lib = "lib/" + libMenu->libName[num];
            graphLib = lib;
            _win->close();
        }
    }
}

void    Sfml::PrevLib()
{
    if (_scenario != USERINPUT) {
        if (_event.type == sf::Event::KeyPressed &&_event.key.code == sf::Keyboard::J) {
            auto it = std::find(libMenu->libName.begin(), libMenu->libName.end(), "lib_arcade_sfml.so");
            int num = std::distance(libMenu->libName.begin(), it);
            num -= 1;
            if (num < 0)
                num = libMenu->libName.size() - 1;
            std::string lib = "lib/" + libMenu->libName[num];
            graphLib = lib;
            _win->close();
        }
     }
}

void    Sfml::init()
{
    _win = new sf::RenderWindow({820, 580}, "SFML - Arcade", sf::Style::Default);
    _menu.push_back(new TextObject(5, 25));
    _menu[0]->setText("Enter your name: ");
    _menu.push_back(new TextObject(5, 100));
    _menu.push_back(new TextObject(5, 175));
    _menu.push_back(new TextObject(5, 250));
    _menu[1]->setText("libraries in \"./games\"");
    _menu[2]->setText("libraries in \"./lib\"");
    _menu[3]->setText("Scores");
    _inputText = new TextObject(_menu[0]->text.getLocalBounds().width, 25);
    _inputText->text.setFillColor(sf::Color::Red);
    select = new RectObject(300, 100);
    sf::Texture *arrowUp = new sf::Texture();
    arrowUp->loadFromFile("./assets/arrowleft.png");
    select->shape.setTexture(arrowUp);
    select->shape.setOrigin(select->shape.getSize().x / 2, -select->shape.getGlobalBounds().height / 2);
    libMenu = new Menu();
    libMenu->libName = getFilesName("./lib");
    for (int i = 0; i < countFiles("./lib"); i++) {
        libMenu->_libs.push_back(new TextObject(5, 25 * (i + 1)));
        libMenu->_libs[i]->setText(libMenu->libName[i]);
    }
    libGame = new Menu();
    libGame->libName = getFilesName("./games");
    for (int i = 0; i < countFiles("./games"); i++) {
        libGame->_libs.push_back(new TextObject(5, 25 * (i + 1)));
        libGame->_libs[i]->setText(libGame->libName[i]);
    }
    gameStatus = true;
}

static bool endsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

std::vector<std::string>    Sfml::getFilesName(std::string path)
{
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

int Sfml::countFiles(std::string path)
{
    int num = 0;
    DIR *pdir = NULL;
    dirent  *pent = NULL;
    
    pdir = opendir(path.c_str());
    while (pent = readdir(pdir))
        if (endsWith(pent->d_name, ".so"))
            num++;
    closedir(pdir);
    return num;
}

IGameModule*     Sfml::start(IGameModule *_game)
{
    while (_win->isOpen()) {
        _win->setFramerateLimit(60);
        handleEvents();
        if (_game == NULL) {
            if (_scenario == USERINPUT) {
                _win->clear();
                _inputText->setText(_userName);
                _menu[0]->blink();
                _win->draw(_menu[0]->text);
                _win->draw(_inputText->text);
            }
            if (_scenario == MENU) {
                _win->clear();
                _menu[0]->text.setOutlineThickness(0);
                _menu[0]->setText("Welcome " + _userName);
                _menu[0]->text.setFillColor(sf::Color::Red);
                for (auto obj : _menu)
                    _win->draw(obj->text);
                _win->draw(select->shape);
            }
            if (_scenario == CHOOSEGAME) {
                _win->clear();
                for (auto lib : libGame->_libs)
                    _win->draw(lib->text);
            }
            if (_scenario == CHOOSELIB) {
                _win->clear();
                for (auto lib : libMenu->_libs)
                    _win->draw(lib->text);
            }
            if (_scenario == SCORES) {
                _win->clear();
                std::ifstream file("scores.txt");
                std::string str;
                std::vector<TextObject*>    score;
                TextObject  title(5, 0);
                title.setText("Last 10");
                if (file.is_open()) {
                    for (int i = 0; std::getline(file, str); i++) {
                        score.push_back(new TextObject(5, 25 * (i + 1)));
                        score[i]->setText(str);
                    }
                    file.close();
                }
                _win->draw(title.text);
                for (auto obj : score) {
                    _win->draw(obj->text);
                }
            }
            game_loop();
        }
        if (_game != NULL) {
            game = _game;
            _scenario = GAMEMODE;
            game_loop();
        }
        _win->display();
    }
    return game;  
}

void    Sfml::game_loop()
{
    if (_scenario == GAMEMODE) {
        if (gameStatus == false) {
            std::ofstream   file("scores.txt", std::fstream::app);
            if (file.is_open()) {
                file << _userName << " " << (game->get_size() - 4) << "\n";
                file.close();
            }
            _win->close();
        }
        _win->setFramerateLimit(5);
        _win->clear();
        loadMap();
        gameStatus = game->play();
    }
}

void    Sfml::loadMap()
{
    std::vector<std::string>    map = game->get_map();

    if (arrayMap.empty()) {
        for (std::vector<std::string>::iterator it = map.begin(); it != map.end(); ++it) {
            for (std::string::iterator c = it->begin(); c != it->end(); ++c) {
                if (*c == '#')
                    arrayMap.push_back(new RectObject(25 * (c - it->begin()), 25 * (it - map.begin()), sf::Color::Blue));
                if (*c == ' ')
                    arrayMap.push_back(new RectObject(25 * (c - it->begin()), 25 * (it - map.begin()), sf::Color::Transparent));
                if (*c == '$')
                    arrayMap.push_back(new RectObject(25 * (c - it->begin()), 25 * (it - map.begin()), sf::Color::Green));
                if (*c == '>')
                    arrayMap.push_back(new RectObject(25 * (c - it->begin()), 25 * (it - map.begin()), sf::Color::Red));
                if (*c == '<')
                    arrayMap.push_back(new RectObject(25 * (c - it->begin()), 25 * (it - map.begin()), sf::Color::Cyan));
                
                if (*c == '!')
                    arrayMap.push_back(new RectObject(25 * (c - it->begin()), 25 * (it - map.begin()), sf::Color(20, 40, 100, 255)));
                if (*c == 'o')
                    arrayMap.push_back(new RectObject(25 * (c - it->begin()), 25 * (it - map.begin()), sf::Color::White));
                if (*c == 'O')
                    arrayMap.push_back(new RectObject(25 * (c - it->begin()), 25 * (it - map.begin()), sf::Color::Magenta));
                if (*c == 'C')
                    arrayMap.push_back(new RectObject(25 * (c - it->begin()), 25 * (it - map.begin()), sf::Color::Yellow));
            }
        }
    }
    for (auto rect : arrayMap)
        _win->draw(rect->shape);
    TextObject  *score = new TextObject(5, 350);
    TextObject  *time = new TextObject(5, 450);
    std::stringstream   ss;
    ss << (game->get_size() - 4);
    score->setText("Score : " + ss.str());
    std::stringstream   dd;

    dd << game->get_game_time();
    time->setText("Time : " + dd.str());
    _win->draw(score->text);
    _win->draw(time->text);
    arrayMap.clear();
}

void    Sfml::set_direc()
{
    if (_scenario == GAMEMODE) {
        if (_event.type == sf::Event::KeyPressed &&_event.key.code == sf::Keyboard::Up)
            game->set_dir('t');
        if (_event.type == sf::Event::KeyPressed &&_event.key.code == sf::Keyboard::Down)
            game->set_dir('b');
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Left)
            game->set_dir('l');
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Right)
            game->set_dir('r');
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Q) {
            _scenario = CHOOSEGAME;
            // game = NULL;
        }
    }
}

void    Sfml::returnToMenu()
{
    if (_scenario == CHOOSEGAME || _scenario == CHOOSELIB || _scenario == SCORES) {
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Q)
            _scenario = MENU;
    }
}

void    Sfml::moveSelect()
{
    sf::Vector2f    pos = select->shape.getPosition();
    if (_scenario == MENU) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            select->shape.setPosition(pos.x, pos.y + 75);
            if (pos.y >= 250) 
                select->shape.setPosition(pos.x, 100);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            select->shape.setPosition(pos.x, pos.y - 75);
            if (pos.y <= 100)
                select->shape.setPosition(pos.x, 250);
        }        
    }
}

void    Sfml::moveSelectLib(Sfml::Menu *lib, Sfml::Scenarios scenario)
{
    if (_scenario == scenario) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            lib->removeHighlight();
            lib->currentNum++;
            if (lib->currentNum > lib->_libs.size() - 1)
                lib->currentNum = 0;
            lib->_libs[lib->currentNum]->text.setOutlineColor(sf::Color::Red);
            lib->_libs[lib->currentNum]->text.setOutlineThickness(2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            lib->removeHighlight();
            lib->currentNum--;
            if (lib->currentNum < 0)
                lib->currentNum = lib->_libs.size() - 1;
            lib->_libs[lib->currentNum]->text.setOutlineColor(sf::Color::Red);
            lib->_libs[lib->currentNum]->text.setOutlineThickness(2);
        }
    }
}

void    Sfml::selectGame()
{
    if (_scenario == CHOOSEGAME) {
        if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Return) {
            std::string lib = "games/" + libGame->_libs[libGame->checkCurrentHighlighted()]->text.getString();
            void    *handle = dlopen(lib.c_str(), RTLD_LAZY);
            init_g  *init_game = (init_g*)dlsym(handle, "init");
            game = init_game();
            game->init();
            _gameLib = lib.substr(lib.find("/") + 1);
            _scenario = GAMEMODE;
        }
    }
}

void    Sfml::menuSelect()
{
    if (_scenario == MENU) {
        if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Return) {
            if (select->shape.getPosition().y == 100)
                _scenario = CHOOSEGAME;
            if (select->shape.getPosition().y == 175)
                _scenario = CHOOSELIB;
            if (select->shape.getPosition().y == 250)
                _scenario = SCORES;
        }
    }
}

void    Sfml::stop()
{
    if (_event.type == sf::Event::Closed ||( _event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Escape) )
        _win->close();
}

void    Sfml::handleEvents()
{
    while (_win->pollEvent(_event)) {
        _win->setKeyRepeatEnabled(false);
        selectGame();
        menuSelect();
        setUserName();
        stop();
        moveSelect();
        moveSelectLib(libMenu, CHOOSELIB);
        moveSelectLib(libGame, CHOOSEGAME);
        returnToMenu();
        required_actions();
    }
}

std::string Sfml::setUserName()
{
    if (_scenario == USERINPUT) {
        if (_event.type == sf::Event::TextEntered && _event.text.unicode != 13) {
            if (_event.text.unicode == 8)
                _userName = _userName.substr(0, _userName.size() - 1);
            else 
                _userName += _event.text.unicode;
        }
        if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Return)
            _scenario = MENU;
    }
    return _userName;
}

std::string Sfml::get_graph_lib()
{
    return graphLib;
}
