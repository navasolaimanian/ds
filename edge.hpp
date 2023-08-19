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
    int galaxy1Id;
    int galaxy2Id;
    std::string node1Name;
    std::string node2Name;
public:
    Edge(int , int , int , int, int, std::string, std::string); // cunstructor

    int getNode1ID(); // get id of first node

    void setNode1ID(int); // set id of first node

    int getNode2ID(); // get id of second node

    void setNode2ID(int); // set id of second node

    int getCost();

    void setCost(int);

    int getGalaxy1Id() { return galaxy1Id; };

    int getGalaxy2Id() { return galaxy2Id; };

    std::string getNode1Name() { return node1Name; };
    
    std::string getNode2Name() { return node2Name; };


};

#endif
