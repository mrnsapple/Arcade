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
    _title = new TextObject((_win->getSize().x / 2) - 35, 5);
    _title->setText("Arcade");
    _enterName = new TextObject((_win->getSize().x / 2) - 80, 50);
    _enterName->setText("Enter your name");
    _inputText = new TextObject((_win->getSize().x / 2) - 30, 120);
    _inputText->text.setCharacterSize(40);
    welcome = new TextObject(10, 5);
}

Sfml::~Sfml()
{

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
        }
        if (_scenario == MENU) {
            _win->clear();
            _win->draw(_title->text);
            welcome->setText("Welcome " + _userName);
            _win->draw(welcome->text);
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
