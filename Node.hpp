#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include"Edge.hpp"

class Node
{
private:
    int id;
    std::string name;
    bool isBorderGateway;

public:
    std::vector<Edge> neighbors; // Assuming Edge is the class defined in Edge.hpp
    Node(int, bool, std::string);
    int getID();
    void setID(int);
    std::string getName();
    void setName(std::string);
    bool getBG();
    void setBG(bool);
};
#endif
