#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "inventory.h"
#include "../node/node.h"
#include "../boost_serialization_includes.h"

using namespace std;

namespace Engine{


/**
 * @brief Class of the player
 * 
 */
class Player{
    private:
        //Necessary to have access the serialization library
        friend class boost::serialization::access;
        
        Inventory inventory;
        string name;
        vector<int> stats;
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

        //Necessary function to serialize the object's fields in order to save and load it
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & name;
            ar & stats;
            ar & commands;
            ar & inventory;
            ar & *currentNode;
        }

        //Setters getters
        void setInventory(Inventory inventory);
        Inventory getInventory();

        void setName(string name);
        string getName();

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