/*
** EPITECH PROJECT, 2019
** OOP
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
    virtual void    stop() = 0;
    virtual const std::string   &getName() const = 0;
};

typedef IDisplayModule  *init_t();
typedef void    destroy_t(IDisplayModule*);

#endif /* !IDISPLAYMODULE_HPP_ */
