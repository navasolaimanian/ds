#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <regex>
#include "Node.hpp"
#include "edge.hpp"
#include "Galaxy.hpp"
#include "ConcreteNode.hpp"
#include "Universe.hpp"
using namespace std;

int main()
{
    Universe universe;

    // add galaxy
    universe.addGalaxy(Galaxy("a", 1));
    universe.addGalaxy(Galaxy("b", 2));
    // universe.addGalaxy(Galaxy("c", 3));
    // add node
    Galaxy *targetGalaxy = universe.getGalaxyByName("a");
    targetGalaxy->addNode(new ConcreteNode(1, false, "A"));
    targetGalaxy->addNode(new ConcreteNode(2, false, "B"));
    targetGalaxy->addNode(new ConcreteNode(3, true, "C"));
    targetGalaxy->addNode(new ConcreteNode(4, false, "D"));
    targetGalaxy->addNode(new ConcreteNode(5, false, "E"));
    targetGalaxy->addNode(new ConcreteNode(6, true, "F"));

    targetGalaxy = universe.getGalaxyByName("b");
    targetGalaxy->addNode(new ConcreteNode(1, true, "A"));
    targetGalaxy->addNode(new ConcreteNode(2, true, "B"));
    targetGalaxy->addNode(new ConcreteNode(3, false, "C"));

    // targetGalaxy->addNode(new ConcreteNode(1, false, "1"));
    // targetGalaxy->addNode(new ConcreteNode(2, true, "2"));
    // targetGalaxy->addNode(new ConcreteNode(3, false, "3"));

    // targetGalaxy = universe.getGalaxyByName("b");
    // targetGalaxy->addNode(new ConcreteNode(1, false, "1"));
    // targetGalaxy->addNode(new ConcreteNode(2, true, "2"));
    // targetGalaxy->addNode(new ConcreteNode(3, true, "3"));

    // targetGalaxy = universe.getGalaxyByName("c");
    // targetGalaxy->addNode(new ConcreteNode(1, false, "1"));
    // targetGalaxy->addNode(new ConcreteNode(2, false, "2"));
    // targetGalaxy->addNode(new ConcreteNode(3, false, "3"));
    // targetGalaxy->addNode(new ConcreteNode(4, true, "4"));

    // add road
    Galaxy *targetGalaxyA = universe.getGalaxyByName("a");
    int nodeIdA = targetGalaxyA->getNodeId("A");
    Galaxy *targetGalaxyB = universe.getGalaxyByName("a");
    int nodeIdB = targetGalaxyB->getNodeId("B");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 2, "A", "B");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("A");
    targetGalaxyB = universe.getGalaxyByName("a");
    nodeIdB = targetGalaxyB->getNodeId("D");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 8, "A", "D");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("B");
    targetGalaxyB = universe.getGalaxyByName("a");
    nodeIdB = targetGalaxyB->getNodeId("E");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 6, "B", "E");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("B");
    targetGalaxyB = universe.getGalaxyByName("a");
    nodeIdB = targetGalaxyB->getNodeId("D");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 5, "B", "D");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("D");
    targetGalaxyB = universe.getGalaxyByName("a");
    nodeIdB = targetGalaxyB->getNodeId("E");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 3, "D", "E");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("D");
    targetGalaxyB = universe.getGalaxyByName("a");
    nodeIdB = targetGalaxyB->getNodeId("F");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 2, "D", "F");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("E");
    targetGalaxyB = universe.getGalaxyByName("a");
    nodeIdB = targetGalaxyB->getNodeId("F");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 1, "E", "F");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("E");
    targetGalaxyB = universe.getGalaxyByName("a");
    nodeIdB = targetGalaxyB->getNodeId("C");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 9, "E", "C");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("F");
    targetGalaxyB = universe.getGalaxyByName("a");
    nodeIdB = targetGalaxyB->getNodeId("C");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 3, "F", "C");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("F");
    targetGalaxyB = universe.getGalaxyByName("b");
    nodeIdB = targetGalaxyB->getNodeId("B");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 4, "F", "B");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("F");
    targetGalaxyB = universe.getGalaxyByName("b");
    nodeIdB = targetGalaxyB->getNodeId("A");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 2, "F", "A");

    targetGalaxyA = universe.getGalaxyByName("a");
    nodeIdA = targetGalaxyA->getNodeId("C");
    targetGalaxyB = universe.getGalaxyByName("b");
    nodeIdB = targetGalaxyB->getNodeId("A");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 8, "C", "A");

    targetGalaxyA = universe.getGalaxyByName("b");
    nodeIdA = targetGalaxyA->getNodeId("A");
    targetGalaxyB = universe.getGalaxyByName("b");
    nodeIdB = targetGalaxyB->getNodeId("B");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 1, "A", "B");

    targetGalaxyA = universe.getGalaxyByName("b");
    nodeIdA = targetGalaxyA->getNodeId("A");
    targetGalaxyB = universe.getGalaxyByName("b");
    nodeIdB = targetGalaxyB->getNodeId("C");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 1, "A", "C");

    targetGalaxyA = universe.getGalaxyByName("b");
    nodeIdA = targetGalaxyA->getNodeId("B");
    targetGalaxyB = universe.getGalaxyByName("b");
    nodeIdB = targetGalaxyB->getNodeId("C");
    universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, 1, "B", "C");


    universe.findPath("a", "A", "b", "C");

    // string input;
    // cout << "Welcom \nfor creating galaxy enter CREATE (AS1: Galaxy, {id:1}) \nfor creating node enter CREATE (A:Node, {id:'1', Type:'BG', Galaxy:AS1}) \nfor creating road enter CREATE (AS1.A) - [:ROAD {cost:50}] -> (AS1.B)\n for exit of program enter exit";
    // cout << "Enter the command: ";
    // getline(cin, input);

    // // pattern of creating galaxy
    // regex createGalaxyPattern(R"(CREATE\s*\(\s*([A-Za-z0-9]+)\s*:\s*Galaxy\s*,\s*\{id:(\d+)\}\s*\))");
    // // pattern of creating node
    // regex createNodePattern(R"(CREATE\s*\(\s*([A-Za-z]+):\s*Node\s*,\s*\{\s*id:\s*'(\d+)',\s*Type:\s*'([A-Za-z]+)',\s*Galaxy:([A-Za-z0-9]+)\s*\}\s*\))");
    // // pattern of creating road
    // regex createRoadPattern(R"(CREATE\s*\((\w+)\.(\w+)\)\s*-\s*\[:ROAD\s*\{cost:(\d+)\}\]\s*->\s*\((\w+)\.(\w+)\))");
    // // pattern of finding road
    // regex findPattern(R"(FIND\s+(\w+)\.(\w+)\s*->\s*(\w+)\.(\w+))");

    // while (input != "exit")
    // {
    //     smatch matches;

    //     // creat galaxy
    //     // CREATE (AS1: Galaxy, {id:1})
    //     if (regex_search(input, matches, createGalaxyPattern) && matches.size() == 3)
    //     {
    //         string galaxyName = matches[1].str();
    //         int galaxyId = stoi(matches[2].str());
    //         //if there is galaxy with this name and id user cant create it
    //         Galaxy *targetGalaxy = universe.getGalaxyByName(galaxyName);
    //         bool isgalaxyId = universe.getGalaxyId(galaxyId);
    //         if (targetGalaxy || isgalaxyId)
    //         {
    //             cout << "there is galaxy with this name" << endl;
    //         }
    //         else
    //         {
    //             universe.addGalaxy(Galaxy(matches[1], galaxyId));

    //             cout << "Galaxy Name: " << galaxyName << endl;
    //             cout << "Galaxy ID: " << galaxyId << endl;
    //         }
    //     }
    //     // create nodes
    //     //  CREATE (A:Node, {id:'1', Type:'BG', Galaxy:AS1})
    //     else if (regex_search(input, matches, createNodePattern))
    //     {
    //         string nodeName = matches[1];
    //         string nodeId = matches[2];
    //         string nodeType = matches[3];
    //         string nodeGalaxy = matches[4];
    //         cout << "Node Name: " << nodeName << endl;
    //         cout << "Node ID: " << nodeId << endl;
    //         cout << "Node Type: " << nodeType << endl;
    //         cout << "Node Galaxy: " << nodeGalaxy << endl;

    //         bool type = (nodeType == "BG") ? true : false;
    //         //if nodes galaxy exist can add node to it
    //         Galaxy *targetGalaxy = universe.getGalaxyByName(nodeGalaxy);

    //         if (targetGalaxy)
    //         {

    //             if (targetGalaxy->nodes.size() == 0)
    //             {
    //                 Node *newNode = new ConcreteNode(stoi(nodeId), type, nodeName);
    //                 targetGalaxy->addNode(newNode);
    //             }
    //             else
    //             {
    //                 for (const auto &n : targetGalaxy->nodes)
    //                 {
    //                     //if node with this name and id exist it can not add to nodes
    //                     if (n->getName() == nodeName || n->getID() == stoi(nodeId))
    //                     {
    //                         cout << "there is node with this name/id in this galaxy" << endl;
    //                         break;
    //                     }
    //                     else
    //                     {
    //                         Node *newNode = new ConcreteNode(stoi(nodeId), type, nodeName);
    //                         targetGalaxy->addNode(newNode);
    //                     }
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             cout << "there is not galaxy with this name";
    //         }
    //     }

    //     // CREATE (AS1.A) – [:ROAD {cost:50}] –> (AS1.B)
    //     else if (regex_search(input, matches, createRoadPattern) && matches.size() == 6)
    //     {
    //         string nodeA = matches[1];
    //         string labelA = matches[2];
    //         string cost = matches[3];
    //         string nodeB = matches[4];
    //         string labelB = matches[5];

    //         cout << "Cost: " << cost << endl;

    //         cout << "Node A: " << nodeA << endl;
    //         Galaxy *targetGalaxyA = universe.getGalaxyByName(nodeA);

    //         cout << "Label A: " << labelA << endl;
    //         int nodeIdA = targetGalaxyA->getNodeId(labelA);

    //         cout << "Node B: " << nodeB << endl;
    //         Galaxy *targetGalaxyB = universe.getGalaxyByName(nodeB);

    //         cout << "Label B: " << labelB << endl;
    //         int nodeIdB = targetGalaxyB->getNodeId(labelB);

    //         universe.addEdge(targetGalaxyA->getID() - 1, targetGalaxyB->getID() - 1, nodeIdA - 1, nodeIdB - 1, stoi(cost));
    //     }

    //     // FIND AS4.W->AS4.X
    //     else if (regex_search(input, matches, findPattern) && matches.size() == 5)
    //     {
    //         string nodeA = matches[1];
    //         string na = matches[2];
    //         string nodeB = matches[3];
    //         string nb = matches[4];

    //         cout << "Node A: " << nodeA << endl;
    //         cout << "Node B: " << nodeB << endl;
    //         cout << "a: " << na << endl;
    //         cout << "B: " << nb << endl;
    //         // universe.findShortestPath(0, 0, 1, 3);
    //     }
    //     else
    //     {
    //         cout << "Invalid Command!" << endl;
    //     }

    //     cout << "Enter the command: ";
    //     getline(cin, input);
    // }
    // return 0;
}

// g++ --std=c++17 main.cpp edge.cpp Galaxy.cpp Node.cpp Universe.cpp ConcreteNode.cpp -o app