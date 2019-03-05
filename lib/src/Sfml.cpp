/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
    _scenario = USERINPUT;
    _win = new sf::RenderWindow({820, 580}, "Arcade", sf::Style::Default);
    _enterName = new TextObject(5, 25);
    _enterName->setText("Enter your name");
    _inputText = new TextObject(_enterName->text.getLocalBounds().width + 20, 10);
    _inputText->text.setCharacterSize(40);
    _inputText->text.setFillColor(sf::Color::Red);
    welcome = new TextObject(5, 10);
    welcome->text.setCharacterSize(40);
    welcome->text.setFillColor(_inputText->text.getFillColor());
    _scores = new TextObject(5, 250);
    _scores->setText("Scores");
}

Sfml::~Sfml()
{

}

static bool endsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

int Sfml::countFiles(std::string path, float x, float y)
{
    int num = 0;
    DIR *pdir = NULL;
    dirent  *pent = NULL;
    std::stringstream   ss;
    TextObject  libNum(x, y);

    pdir = opendir(path.c_str());
    while (pent = readdir(pdir))
        if (endsWith(pent->d_name, ".so"))
            num++;
    closedir(pdir);
    ss << num;
    libNum.setText(ss.str() + " libraries in " + path);
    _win->draw(libNum.text);
    return num;
}

void    Sfml::init()
{
    while (_win->isOpen()) {
        handleEvents();
        if (_scenario == USERINPUT) {
            _win->clear();
            _inputText->setText(_userName);
            _win->draw(_enterName->text);
            _win->draw(_inputText->text);
            countFiles("./lib",5, 100);
            countFiles("./games",5, 175);
            _win->draw(_scores->text);
        }
        if (_scenario == MENU) {
            _win->clear();
            welcome->setText("Welcome " + _userName);
            _win->draw(welcome->text);
            countFiles("./lib", 5, 100);
            countFiles("./games", 5, 175);
            _win->draw(_scores->text);
        }
        _win->display();
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
    }
}

std::string Sfml::setUserName()
{
    if (_scenario == USERINPUT) {
        if (_event.type == sf::Event::TextEntered)
                _userName += _event.text.unicode;
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Return)
            _scenario = MENU;
    }
    return _userName;
}
