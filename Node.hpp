#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include "Edge.hpp"

class Node
{
private:
    int id;               // id of node
    std::string name;     // name of node
    bool isBorderGateway; // is BG or not

public:
    std::vector<Edge> neighbors; // neighbors of node

    Node(int, bool, std::string); // constructor

    int getID(); // get id of node

    void setID(int); // set id of node

    std::string getName(); // get name of node

    void setName(std::string); // set name of node

    bool getBG(); // get BG of node

    void setBG(bool); // set BG of node
};
#endif
