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
    void    start();
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
    void    moveSelectLib();
    std::vector<std::string>    getFilesName(std::string path);
    class Menu {
    public:
        Menu() {
            currentNum = 0;
        }
        int currentNum;
        std::vector<std::string>    libName;
        std::vector<TextObject*>    _libs;
        void    removeHighlight() {
            for (auto lib : _libs)
                lib->text.setOutlineThickness(0);
        }
    };

protected:
    Scenarios   _scenario;
    sf::RenderWindow  *_win;
    sf::Event   _event;
    std::string _userName;
    TextObject  *_inputText;
    std::vector<TextObject*>    _menu;
    RectObject  *select;
    Menu    *libMenu;

private:
};

extern "C" IDisplayModule *init() {
    return new Sfml;
}

#endif /* !SFML_HPP_ */
