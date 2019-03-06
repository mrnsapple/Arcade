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
    _menu.push_back(new TextObject(5, 25));
    _menu[0]->setText("Enter your name");
    _menu.push_back(new TextObject(5, 100));
    _menu.push_back(new TextObject(5, 175));
    _menu.push_back(new TextObject(5, 250));
    _menu[3]->setText("Scores");
    _inputText = new TextObject(_menu[0]->text.getLocalBounds().width + 20, 25);
    _inputText->text.setFillColor(sf::Color::Cyan);
}

Sfml::~Sfml()
{

}

static bool endsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
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

void    Sfml::init()
{
    while (_win->isOpen()) {
        handleEvents();
        if (_scenario == USERINPUT) {
            _win->clear();
            _inputText->setText(_userName);
            _win->draw(_menu[0]->text);
            _win->draw(_inputText->text);
            setLibGames();
            setLibFiles();
            _win->draw(_menu[3]->text);
        }
        if (_scenario == MENU) {
            _win->clear();
            _menu[0]->setText("Welcome " + _userName);
            _menu[0]->text.setFillColor(sf::Color::Cyan);
            _win->draw(_menu[0]->text);
            setLibGames();
            setLibFiles();
            _win->draw(_menu[3]->text);
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
