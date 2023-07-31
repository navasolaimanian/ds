#include "Node.hpp"
#include <iostream>
Node:: Node(int id, bool isBorderGateway, string name) : id(id), isBorderGateway(isBorderGateway), name(name) {}
int Node::getID()
{
    return id;
}
void Node::setID(int idnode)
{
    id = idnode;
}
string Node::getName()
{
    return name;
}
void Node::setName(string nodeName)
{
    name = nodeName;
}
bool Node::getBG()
{
    return isBorderGateway;
}
void setBG(bool BG)
{
    isBorderGateway = BG;
}
