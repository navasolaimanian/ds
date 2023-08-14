#ifndef ConcreteNode_H
#define ConcreteNode_H
#include <iostream>
#include "Node.hpp"

class ConcreteNode : public Node
{
public:
    ConcreteNode(int id, bool isBorderGateway, std::string); // constructor
};

#endif