#ifndef GALAXY_H
#define GALAXY_H
#include <iostream>
#include <vector>
class Node;

class Galaxy
{
private:
    std::string name;
    int id;

public:
    std::vector<Node *> nodes; // لیست نود‌های کهکشان

    Galaxy(const std::string, int);

    // افزودن نود به کهکشان
    void addNode(Node *);
    int getNodeId(const std::string);
    std::string getName();
    void setName(std::string);
    int getID();
    void setID(int);
};

#endif