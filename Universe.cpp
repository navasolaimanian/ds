#include "Universe.hpp"
using namespace std;
#include "Galaxy.hpp"
#include "Edge.hpp"

void Universe::addGalaxy(const Galaxy &galaxy)
{
    galaxies.push_back(galaxy);
    cout << galaxy.getName() << " add to galaxies" << endl;
}

Galaxy *Universe::getGalaxyByName(const string &name)
{

    for (size_t i = 0; i < galaxies.size(); ++i)
    {
        if (galaxies[i].getName() == name)
        {
            return &galaxies[i];
        }
    }
    return nullptr;
}
bool Universe::getGalaxyId(const int id)
{

    for (size_t i = 0; i < galaxies.size(); ++i)
    {
        if (galaxies[i].getID() == id)
        {
            return true;
        }
    }
    return false;
}

void Universe::addEdge(int galaxyIdA, int galaxyIdB, int nodeId1, int nodeId2, int weight, string node1Name, string node2Name)
{
    // check if id of galaxies are valid
    if (galaxyIdA >= galaxies.size() || galaxyIdB >= galaxies.size())
    {
        cout << "Invalid galaxy ID." << endl;
        return;
    }
    // check if id of nodes are valid
    if (nodeId1 >= galaxies[galaxyIdA].nodes.size() || nodeId2 >= galaxies[galaxyIdB].nodes.size())
    {
        cout << "Invalid node ID." << endl;
        return;
    }
    // create Edge and push it into neighbors of node of galaxy
    galaxies[galaxyIdA].nodes[nodeId1]->neighbors.push_back(Edge(nodeId1 + 1, nodeId2 + 1, weight, galaxyIdA + 1, galaxyIdB + 1, node1Name, node2Name));
    galaxies[galaxyIdB].nodes[nodeId2]->neighbors.push_back(Edge(nodeId2 + 1, nodeId1 + 1, weight, galaxyIdB + 1, galaxyIdA + 1, node2Name, node1Name));
}


void Universe::findPath(string galaxyName1, string nodeName1, string galaxyName2 , string nodeName2)
{
    vector<string> pathInGalaxy = getGalaxyByName(galaxyName1)->findPathToBG(nodeName1);

    string cost = pathInGalaxy.back();
    pathInGalaxy.pop_back();
    string nodeName = pathInGalaxy.back();

    int k = 0;
    int travelCost;
    Node * node;
    for(auto i : getGalaxyByName(galaxyName2)->nodes)
    {
        if (i->getBG())
        {
            for (auto j : i->neighbors)
            {
                if (j.getNode2Name() == nodeName)
                {
                    if (k == 0)
                    {
                        k++;
                        travelCost = j.getCost();
                        node = i;
                    } else
                    {
                        if (j.getCost() < travelCost)
                        {
                            travelCost = j.getCost();
                            node = i;
                        }
                    }
                }
            }
        }
    }

    vector<string> pathInGalaxy2 = getGalaxyByName(galaxyName2)->findPath(nodeName2, node->getName());

    string cost1 = pathInGalaxy2.back();
    pathInGalaxy2.pop_back();
    string totalCost = to_string(stoi(cost1) + stoi(cost) + travelCost);

    for (int i = pathInGalaxy2.size() - 1; i >= 0; i--)
    {
        pathInGalaxy.push_back(pathInGalaxy2[i]);
    }

    pathInGalaxy.push_back(totalCost);

    for (auto i : pathInGalaxy)
    {
        cout << i << '\t';
    }
    cout << endl;
}
