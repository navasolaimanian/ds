#ifndef UNIVERSE_H
#define UNIVERSE_H
#include<vector>
#include<iostream>
#include"Galaxy.hpp"
#include"Edge.hpp"
class Universe
{
public:
    std::vector<Galaxy> galaxies; 

    Universe() {}

    void addGalaxy(const Galaxy &);

    Galaxy *getGalaxyByName(const std::string &);
    bool getGalaxyId(const int);

    void addEdge(int , int , int , int , int );

};
#endif