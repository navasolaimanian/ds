#ifndef EDGE_H
#define EDGE_H
#include<vector>
#include<iostream>
class Galaxy;
class Edge;
class Universe
{
public:
    std::vector<Galaxy> galaxies; 

    Universe() {}

    void addGalaxy(Galaxy &);

    Galaxy *getGalaxyByName(const std::string &);
    bool getGalaxyId(const int);

    void addEdge(int , int , int , int , int );

};
#endif