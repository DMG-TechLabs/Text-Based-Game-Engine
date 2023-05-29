#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "inventory.h"
#include "../node/node.h"

using namespace std;

namespace Engine{


/**
 * @brief Class of the player
 * 
 */
class Player{
    private:
        Inventory inventory;
        string name;
        vector<int> stats;
        vector<Objective *> objectives;
    public:
        Node *currentNode;
        Player(){}
        ~Player(){}
        Player(Inventory inventory, string name, vector<int> stats){
            this -> inventory = inventory;
            this -> name = name;
            this -> stats = stats;
        }
        Player(Inventory inventory, string name, vector<int> stats, Node *currentNode){
            this -> inventory = inventory;
            this -> name = name;
            this -> stats = stats;
            this -> currentNode = currentNode;
        }

        //Setters getters
        void setInventory(Inventory inventory);
        Inventory getInventory();

        void setName(string name);
        string getName();
        
        void setObjectives(vector<Objective *> objectives);
        vector<Objective *> getObjectives();

        vector<int> getStats();

        void setCurrentNode(Node *newNode);

        /**
         * @brief Method that moves player to a new node if it is accessible
         * 
         * @param newNode The node the player tries to move to
         */
        void moveToNode(Node *newNode);
        void collectItem(Item *item);
};
}