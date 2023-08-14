#include "Edge.hpp"

Edge::Edge(int node1Id, int node2Id, int weight) : node1Id(node1Id), node2Id(node2Id), weight(weight) {}

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
