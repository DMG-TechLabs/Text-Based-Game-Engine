#pragma once

#include "node.h"

namespace Engine{


class Map{
    public:
        vector<Node*> nodes;

        Map(Node *default_node){
            nodes.push_back(default_node);

            initMap();
        }
        Map(int day, Node *default_node){
            nodes.push_back(default_node);

            initMap(day);
        }
        ~Map(){}

        void initMap(int day);
        void initMap();
        Node *getNode(int id);
        void addNode(Node *node, vector<int> connectedTo = {});
};   
}
