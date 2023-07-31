#include"Galaxy.hpp"
#include"Node.hpp"
#include <iostream>
using namespace std;
Galaxy::Galaxy(const string Name, int id) : name(Name), id(id) {}


void Galaxy::addNode(Node *node)
{
    nodes.push_back(node);
    for (const auto &g : nodes)
    {
        cout << "node Name: " << g->getName() << endl;

    }
}
int Galaxy::getNodeId(const string node)
{

    for (size_t i = 0; i < nodes.size(); ++i)
    {
        if (node == nodes[i]->getName())
        {
            return nodes[i]->getID();
        }
    }
}
string Galaxy::getName()
{
    return name;
}
void Galaxy::setName(string galaxyName)
{
    name = galaxyName;
}
int Galaxy::getID()
{
    return id;
}
void Galaxy::setID(int galaxyId)
{
    id = galaxyId;
}