/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Shared
*/

#ifndef SHARED_HPP_
#define SHARED_HPP_

#include <vector>
#include <string>
#include <iostream>
#include <dirent.h>

class Shared {
public:
    Shared();
    ~Shared();
    std::vector<std::string>    getGraphLibName();
    std::vector<std::string>    getGameLibName();

protected:
private:

};

#endif /* !SHARED_HPP_ */
