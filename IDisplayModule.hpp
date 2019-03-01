/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <iostream>

class IDisplayModule {
public:
    virtual ~IDisplayModule() = default;
    virtual void    init() = 0;
    virtual void    stop() = 0;

protected:
private:
};

typedef IDisplayModule  *init_t();
typedef void    destroy_t();

#endif /* !IDISPLAYMODULE_HPP_ */
