#ifndef GALAXY_H
#define GALAXY_H
#include <iostream>
#include <vector>
#include "Node.hpp"

class Galaxy
{
private:
    std::string name; // name of galaxy
    int id;           // id of galaxy

public:
    std::vector<Node *> nodes; // nodes of galaxy

    Galaxy(const std::string, int); // constructor

    void addNode(Node *); // add node to nodes of galaxy

    int getNodeId(std::string); // return id of nodes name

    std::string getName() const; // get name of galaxy

    void setName(std::string); // set name of galaxy

    int getID(); // get id of galaxy

    void setID(int); // set id of galaxy

    Node * getNode(int); // get node by id

    Node * getNodeByName(std::string); // get node by name

    std::vector<std::string> findPath(std::string, std::string); // find shortest path between 2 node

    std::vector<std::string> findPathToBG(std::string); // find shortest path to a bg node
};

#endif