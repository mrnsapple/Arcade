/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <vector>
#include "dirent.h"
#include "../../IDisplayModule.hpp"
#include "../../TextObject.hpp"
#include "../../RectObject.hpp"

class Sfml : public IDisplayModule {
public:
    Sfml();
    ~Sfml();

    void    init();
    void    stop();
    enum Scenarios {
        USERINPUT,
        MENU,
        CHOOSELIB,
        CHOOSEGAME,
        SCORES
    };
    std::string setUserName();
    void    handleEvents();
    int countFiles(std::string path);
    void    setLibGames();
    void    setLibFiles();
    void    moveSelect();
    void    menuSelect();
    void    returnToMenu();

protected:
    Scenarios   _scenario;
    sf::RenderWindow  *_win;
    sf::Event   _event;
    std::string _userName;
    TextObject  *_inputText;
    std::vector<TextObject*> _menu;
    RectObject  *select;

private:
};

extern "C" IDisplayModule *init() {
    return new Sfml;
}

#endif /* !SFML_HPP_ */
