#ifndef EDGE_H
#define EDGE_H

// class of edge for 2 node
class Edge
{
private:
    int node1Id; // The ID of the first node connected by the edge
    int node2Id; // The ID of the second node connected by the edge
    int weight;  // The weight/cost of the edge
public:
    Edge(int, int, int); // cunstructor

    int getNode1ID(); // get id of first node

    void setNode1ID(int); // set id of first node

    int getNode2ID(); // get id of second node

    void setNode2ID(int); // set id of second node
};

#endif
