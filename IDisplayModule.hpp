/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <iostream>
#include <string>

class IDisplayModule {
public:
    virtual ~IDisplayModule() = default;
    virtual void    init() = 0;
    virtual void    start() = 0;
    virtual void    stop() = 0;
    virtual std::string setUserName() = 0;
    virtual void    NextLib() = 0;

protected:
private:
};

typedef IDisplayModule  *init_t();

#endif /* !IDISPLAYMODULE_HPP_ */
