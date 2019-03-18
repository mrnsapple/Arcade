/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml
*/

#include "Sfml.hpp"

Sfml::Sfml()
{

}

Sfml::~Sfml()
{

}

void    Sfml::init()
{
    _scenario = USERINPUT;
    _win = new sf::RenderWindow({820, 580}, "Arcade", sf::Style::Default);
    _win->setFramerateLimit(60);
    _menu.push_back(new TextObject(5, 25));
    _menu[0]->setText("Enter your name: ");
    _menu.push_back(new TextObject(5, 100));
    _menu.push_back(new TextObject(5, 175));
    _menu.push_back(new TextObject(5, 250));
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

void    Sfml::setLibGames()
{
    std::stringstream   ss;

    ss << countFiles("./games");
    _menu[1]->setText(ss.str() + " libraries in " + "\"./games\"");
    _win->draw(_menu[1]->text);
}

void    Sfml::setLibFiles()
{
    std::stringstream   ss;

    ss << countFiles("./lib");
    _menu[2]->setText(ss.str() + " libraries in " + "\"./lib\"");
    _win->draw(_menu[2]->text);
}

void    Sfml::start()
{
    while (_win->isOpen()) {
        handleEvents();
        if (_scenario == USERINPUT) {
            _win->clear();
            _inputText->setText(_userName);
            _menu[0]->blink();
            _win->draw(_menu[0]->text);
            _win->draw(_inputText->text);
            setLibGames();
            setLibFiles();
            _win->draw(_menu[3]->text);
        }
        if (_scenario == MENU) {
            _win->clear();
            _menu[0]->text.setOutlineThickness(0);
            _menu[0]->setText("Welcome " + _userName);
            _menu[0]->text.setFillColor(sf::Color::Red);
            _win->draw(_menu[0]->text);
            setLibGames();
            setLibFiles();
            _win->draw(_menu[3]->text);
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
            _win->clear(sf::Color::Green);
        }
        
        _win->display();
    }
}

void    Sfml::runTransition(Sfml::Scenarios scene)
{
    _scenario = scene;
}

void    Sfml::returnToMenu()
{
    if (_scenario == CHOOSEGAME || _scenario == CHOOSELIB || _scenario == SCORES) {
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
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
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Space) {
            std::cout << (std::string)libGame->_libs[libGame->checkCurrentHighlighted()]->text.getString() << std::endl;
        }
    }
    
}

void    Sfml::menuSelect()
{
    if (_scenario == MENU) {
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Space) {
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
    if (_event.type == sf::Event::Closed)
        _win->close();
}

void    Sfml::handleEvents()
{
    while (_win->pollEvent(_event)) {
        setUserName();
        stop();
        moveSelect();
        moveSelectLib(libMenu, CHOOSELIB);
        moveSelectLib(libGame, CHOOSEGAME);
        menuSelect();
        selectGame();
        returnToMenu();
    }
}

std::string Sfml::setUserName()
{
    if (_scenario == USERINPUT) {
        if (_event.type == sf::Event::TextEntered) {
            if (_event.text.unicode == 8)
                _userName = _userName.substr(0, _userName.size() - 1);
            else
                _userName += _event.text.unicode;
        }
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Return)
            _scenario = MENU;
    }
    return _userName;
}
