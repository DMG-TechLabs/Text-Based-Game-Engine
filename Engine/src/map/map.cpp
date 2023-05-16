#include "map.h"

using namespace Engine;

bool exists(vector<int> vector, int s);

void Map::addNode(Node *node, vector<int> connectedTo) {
    vector<Node *> nodesToConnect;
    for (int i = 0; i < nodes.size(); i++) {
        if (exists(connectedTo, nodes.at(i)->id))
            nodesToConnect.push_back(nodes.at(i));
    }

    for (int i = 0; i < nodesToConnect.size(); i++) {
        node->addRoute(
            nodesToConnect.at(i));  // connect other nodes to new node
        for (int j = 0; j < nodes.size(); j++) {
            if (nodesToConnect.at(i)->id == nodes.at(j)->id)
                nodes.at(j)->addRoute(node);  // connect new node to other nodes
        }
    }

    this->nodes.push_back(node);
}

Node *Map::getNode(int id) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i)->id == id) return nodes.at(i);
    }
    return NULL;
}


bool exists(vector<int> vector, int s) {
    for (size_t i = 0; i < vector.size(); i++) {
        if (vector.at(i) == s) return true;
    }

    return false;
}