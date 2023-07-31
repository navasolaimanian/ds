#ifndef EDGE_H
#define EDGE_H
#include <iostream>

// class of edge for 2 node
class Edge
{
private:
    int node1Id; // The ID of the first node connected by the edge
    int node2Id; // The ID of the second node connected by the edge
    int weight;  // The weight/cost of the edge
public:
    // cunstructor
    Edge(int , int , int );
    int getNode1ID();
    void setNode1ID(int);
    int getNode2ID();
    void setNode2ID(int);

};

#endif
