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
#include "../IDisplayModule.hpp"
#include "TextObject.hpp"
#include "RectObject.hpp"
#include "../IGameModule.hpp"

class Sfml : public IDisplayModule {
public:
    Sfml();
    ~Sfml();

    void    init();
     IGameModule *     start(IGameModule *game);
    void    stop();
    void    NextLib();
    void    PrevLib();
    bool    required_actions();
    void    game_loop();
    void    initialize_values() {}
    void    NextGame();
    void    PrevGame();
    std::string get_graph_lib();

    enum Scenarios {
        USERINPUT,
        MENU,
        CHOOSELIB,
        CHOOSEGAME,
        SCORES,
        GAMEMODE
    };
    class Menu {
    public:
        Menu() {
            currentNum = 0;
        }
        int currentNum;
        std::vector<std::string>    libName;
        std::vector<TextObject*>    _libs;
        int checkCurrentHighlighted() {
            for (int i = 0; i < _libs.size(); i++)
                if (_libs[i]->text.getOutlineThickness() == 2)
                    return i;
        }
        void    removeHighlight() {
            for (auto lib : _libs)
                lib->text.setOutlineThickness(0);
        }
    };

    std::string setUserName();
    void    handleEvents();

    int countFiles(std::string path);
    std::vector<std::string>    getFilesName(std::string path);

    void    moveSelect();
    void    menuSelect();
    
    void    returnToMenu();
    
    void    moveSelectLib(Menu *lib, Scenarios);
    void    selectGame();
    void    loadMap();
    void    set_direc();
    void    restartGame();

protected:
    Scenarios   _scenario;
    sf::RenderWindow  *_win;
    sf::Event   _event;
    std::string _userName;
    TextObject  *_inputText;
    std::vector<TextObject*>    _menu;
    RectObject  *select;
    Menu    *libMenu;
    Menu    *libGame;
    IGameModule *game;
    std::vector<RectObject*> arrayMap;
    bool    gameStatus;
    std::string graphLib;
    std::string _gameLib;

private:
};

extern "C" IDisplayModule *init() {
    return new Sfml;
}

#endif /* !SFML_HPP_ */
