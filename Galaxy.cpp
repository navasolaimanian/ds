#include "Galaxy.hpp"
#include "Node.hpp"
#include <iostream>
#include <map>
#include<algorithm>
using namespace std;

Galaxy::Galaxy(const string Name, int id) : name(Name), id(id) {}

void Galaxy::addNode(Node *node)
{
    nodes.push_back(node);
    for (const auto &g : nodes)
    {
        cout << "nodes of galaxy: " << g->getName() << " ";
    }
}
int Galaxy::getNodeId(string node)
{

    for (size_t i = 0; i < nodes.size(); ++i)
    {
        if (node == nodes[i]->getName())
        {
            return nodes[i]->getID();
        }
    }
    return -1;
}
string Galaxy::getName() const
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

Node* Galaxy::getNode(int id)
{
    return nodes[id - 1];
}

Node * Galaxy::getNodeByName(string name)
{
    for(auto i : nodes)
    {
        if (i->getName() == name)
        {
            return i;
        }
    }
    cout << "node not found!" << endl;
    return nullptr;
}

vector<string> Galaxy::findPath(string start, string end)
{
    map<string, int> table;
    vector<string> visited;
    visited.push_back(start);

    map<string, vector<string> > path;

    
    for (size_t i = 0; i < nodes.size(); i++)
    {
        if (nodes[i]->getName() == start)
        {
            continue;
        }
        table.insert({nodes[i]->getName(), -1});
        vector<string> tmp;
        tmp.push_back(start);
        path.insert({nodes[i]->getName(), tmp});
    }

    for (auto i : getNode(getNodeId(start))->neighbors)
    {
        table[getNode(i.getNode2ID())->getName()] = i.getCost();
    }

    for (size_t l = 0; l < table.size(); l++)
    {
        string min;
        int j = 0;
        for (auto i : table)
        {
            auto it = find(visited.begin(), visited.end(), i.first);
            if (it != visited.end())
            {
                continue;
            }
            if (j == 0)
            {
                if (i.second != -1)
                {
                    min = i.first;
                    j++;
                }
                continue;
            }
            if (i.second < table[min] && i.second != -1)
            {
                min = i.first;
            }
        }

        for(auto i : getNodeByName(min)->neighbors)
        {
            if (i.getNode2Name() == i.getNode1Name())
            {
                auto it = find(visited.begin(), visited.end(), getNode(i.getNode2ID())->getName());
                if (it == visited.end())
                {
                    int cost = table[min] + i.getCost();
                    if (cost < table[getNode(i.getNode2ID())->getName()] || table[getNode(i.getNode2ID())->getName()] == -1)
                    {
                        vector<string> tmp = path[getNode(i.getNode1ID())->getName()];
                        tmp.push_back(min);
                        path[getNode(i.getNode2ID())->getName()] = tmp;
                        table[getNode(i.getNode2ID())->getName()] = cost;
                        
                    }
                }
            }
            visited.push_back(min);
        }
    }
    
    for(auto &i : path)
    {
        if (i.first == end)
        {
            i.second.push_back(end);
            i.second.push_back(to_string(table[end]));
            return i.second;
        }
        
    }
    return {};
}


vector<string> Galaxy::findPathToBG(string nodeName)
{
    map<string, int> table;
    vector<string> visited;
    visited.push_back(nodeName);

    map<string, vector<string> > path;

    for (size_t i = 0; i < nodes.size(); i++)
    {
        if (nodes[i]->getName() == nodeName)
        {
            continue;
        }
        table.insert({nodes[i]->getName(), -1});
        vector<string> tmp;
        tmp.push_back(nodeName);
        path.insert({nodes[i]->getName(), tmp});
    }

    for (auto i : getNode(getNodeId(nodeName))->neighbors)
    {
        table[getNode(i.getNode2ID())->getName()] = i.getCost();
    }

    for (size_t l = 0; l < table.size(); l++)
    {
        string min;
        int j = 0;
        for (auto i : table)
        {
            auto it = find(visited.begin(), visited.end(), i.first);
            if (it != visited.end())
            {
                continue;
            }
            if (j == 0)
            {
                if (i.second != -1)
                {
                    min = i.first;
                    j++;
                }
                continue;
            }
            if (i.second < table[min] && i.second != -1)
            {
                min = i.first;
            }
        }
        
        for(auto i : getNodeByName(min)->neighbors)
        {
            auto it = find(visited.begin(), visited.end(), getNode(i.getNode2ID())->getName());
            if (it == visited.end())
            {
                int cost = table[min] + i.getCost();
                if (cost < table[getNode(i.getNode2ID())->getName()] || table[getNode(i.getNode2ID())->getName()] == -1)
                {
                    vector<string> tmp = path[getNode(i.getNode1ID())->getName()];
                    tmp.push_back(min);
                    path[getNode(i.getNode2ID())->getName()] = tmp;
                    table[getNode(i.getNode2ID())->getName()] = cost;
                }
            }
        }
        visited.push_back(min);
    }

    vector<string> tmp;
    int j = 0;
    for(auto &i : path)
    {
        if (getNodeByName(i.first)->getBG())
        {
            if (j == 0)
            {
                j++;
                tmp = i.second;
                tmp.push_back(i.first);
                
                continue;
            } else
            {
                if (table[tmp.back()] > table[i.first])
                {
                    tmp = i.second;
                    tmp.push_back(i.first);
                }
            }
        }
    }
    tmp.push_back(to_string(table[tmp.back()]));
    return tmp;
}
