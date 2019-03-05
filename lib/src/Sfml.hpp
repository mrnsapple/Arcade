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
#include "../../IDisplayModule.hpp"
#include "TextObject.hpp"
#include "dirent.h"
#include <sstream>

class Sfml : public IDisplayModule {
public:
    Sfml();
    ~Sfml();

    void    init();
    void    stop();
    enum Scenarios {
        USERINPUT,
        MENU
    };
    std::string setUserName();
    void    handleEvents();
    int countFiles(std::string path, float x, float y);

protected:
    Scenarios   _scenario;
    sf::RenderWindow  *_win;
    sf::Event   _event;
    TextObject  *_enterName;
    std::string _userName;
    TextObject  *_inputText;
    TextObject  *welcome;
    TextObject  *_scores;
private:
};

extern "C" IDisplayModule *init() {
    return new Sfml;
}

#endif /* !SFML_HPP_ */
