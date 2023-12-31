#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <vector>
#include <iostream>
#include "Galaxy.hpp"
#include "edge.hpp"

class Universe
{
public:
    std::vector<Galaxy> galaxies; // for storing all galaxies in universe

    void addGalaxy(const Galaxy &); // for adding galaxy to galaxies in universe

    Galaxy *getGalaxyByName(const std::string &); // returining galaxy if it is exist by its name

    bool getGalaxyId(const int); // returning true if there is galaxy with this id

    void addEdge(int , int , int , int , int, std::string, std::string); // adding edge between to node

    void findPath(std::string, std::string, std::string, std::string);
};
#endif