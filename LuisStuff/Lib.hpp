/*
** EPITECH PROJECT, 2019
** OOP
** File description:
** Lib
*/

#ifndef LIB_HPP_
#define LIB_HPP_

#include "IDisplayModule.hpp"

class Lib : public IDisplayModule {
public:
    Lib();
    ~Lib();
    const std::string &getName() const {
        return _name;
    }
    void init();
    void stop();
    int entryPoint() {
        std::cout << "TREXT JERE" << std::endl;
    }
private:
    std::string _name;
};

extern "C" IDisplayModule *init() {
    return new Lib;
}


#endif /* !LIB_HPP_ */
