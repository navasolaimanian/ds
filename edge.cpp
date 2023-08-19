#include "edge.hpp"
#include <iostream>

using namespace std;

// Constructor implementation
Edge::Edge(int node1Id, int node2Id, int weight, int galaxy1Id, int galaxy2Id, string node1Name, string node2Name)
    : node1Id(node1Id), node2Id(node2Id), weight(weight), galaxy1Id(galaxy1Id), galaxy2Id(galaxy2Id), node1Name(node1Name), node2Name(node2Name){}

int Edge::getNode1ID()
{
    return node1Id;
}

void Edge::setNode1ID(int nodeId)
{
    node1Id = nodeId;
}

int Edge::getNode2ID()
{
    return node2Id;
}

void Edge::setNode2ID(int nodeId)
{
    node2Id = nodeId;
}

int Edge::getCost()
{
    return weight;
}

void Edge::setCost(int cost)
{
    weight = cost;
}