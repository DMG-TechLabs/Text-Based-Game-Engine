#pragma once

#include <string>
#include <vector>
#include "../player/inventory.h"
#include "../item/item.h"
#include "../utils/prompt.h"

using namespace std;

/**
 * @brief Node class. Each node represents a place where the player can move to
 */
class Node{
    private:

    public:
        int id;
        string description;
        vector<Item> *items;
        vector<Node> *accesible_nodes;
        bool accesible;

        /**
         * @brief Construct a new Node object. Default constructor
         */
        Node(){}

        /**
         * @brief Destroy the Node object
         */
        ~Node(){}

        /**
         * @brief Construct a new Node object.
         * 
         * @param id Node id
         * @param description Node description
         * @param items Items inide the node
         * @param accesible_nodes Nodes the player can try to move from current node
         * @param accesible Accesibility of the current node
         */
        Node(int id, string description, vector<Item> *items, vector<Node> *accesible_nodes, bool accesible){
            this-> id = id;
            this-> description = description; 
            this-> items = items;
            this-> accesible_nodes = accesible_nodes;
            this-> accesible = accesible;
        }

        /**
         * @brief Construct a new Node object. Constructor for inaccesible rooms
         * 
         * @param description Description will be the only thing needed for if the player tries to enter, he will not be allowed
         *                    and the node description will be printed
         */
        Node(string description){
            this->accesible = false;
            this->description = description;
        }
};   