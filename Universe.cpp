
#include "Universe.hpp"
using namespace std;
#include"Galaxy.hpp"
#include"Edge.hpp"

// Universe::Universe() {}


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


void Universe::addEdge(int galaxyIdA, int galaxyIdB, int nodeId1, int nodeId2, int weight)
{
    if (galaxyIdA >= galaxies.size() || galaxyIdB >= galaxies.size())
    {
        cout << "Invalid galaxy ID." << endl;
        return;
    }

    if (nodeId1 >= galaxies[galaxyIdA].nodes.size() || nodeId2 >= galaxies[galaxyIdB].nodes.size())
    {
        cout << "Invalid node ID." << endl;
        return;
    }

    galaxies[galaxyIdA].nodes[nodeId1]->neighbors.push_back(Edge(nodeId1, nodeId2, weight));
    galaxies[galaxyIdB].nodes[nodeId2]->neighbors.push_back(Edge(nodeId2, nodeId1, weight));
}
