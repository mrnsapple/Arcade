/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Shared
*/

#include "Shared.hpp"

Shared::Shared()
{
}

Shared::~Shared()
{
}

static bool endsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

std::vector<std::string>    Shared::getGraphLibName()
{
    std::vector<std::string>    vec;
    DIR *pdir = NULL;
    dirent  *pent = NULL;

    pdir = opendir("./lib");
    while (pent = readdir(pdir))
        if (endsWith(pent->d_name, ".so"))
            vec.push_back(pent->d_name);
    closedir(pdir);
    return vec;
}

std::vector<std::string>    Shared::getGameLibName()
{
    std::vector<std::string>    vec;
    DIR *pdir = NULL;
    dirent  *pent = NULL;

    pdir = opendir("./games");
    while (pent = readdir(pdir))
        if (endsWith(pent->d_name, ".so"))
            vec.push_back(pent->d_name);
    closedir(pdir);
    return vec;
}
