#pragma once

#include "inventory.h"
#include "item.h"
#include "prompt.h"
#include "boost_serialization_includes.h"

#include <string>
#include <vector>

using namespace std;

namespace Engine{

/**
 * @brief Node class. Each node represents a place where the player can move to
 */
class Node{
    private:
        //Necessary to have access the serialization library
        friend class boost::serialization::access;
        
        bool accessible = false;

    public:
        int id;
        string description;
        vector<Item*> items;
        vector<Node*> accessible_nodes;

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
         * @param accessible_nodes Nodes the player can try to move from current node
         * @param accessible Accesibility of the current node
         */
        Node(int id, string description, vector<Item*> items, vector<Node*> accessible_nodes, bool accessible){
            this-> id = id;
            this-> description = description; 
            this-> items = items;
            this-> accessible_nodes = accessible_nodes;
            this-> accessible = accessible;
        }
        
        /**
         * @brief Construct a new Node object.
         * 
         * @param id Node id
         * @param description Node description
         * @param items Items inide the node
         */
        Node(int id, string description, vector<Item*> items){
            this-> id = id;
            this-> description = description; 
            this-> items = items;
            this-> accessible = false;
        }

        /**
         * @brief Construct a new Node object. Constructor for inaccesible rooms
         * 
         * @param description Description will be the only thing needed for if the player tries to enter, he will not be allowed
         *                    and the node description will be printed
         */
        Node(string description){
            this->accessible = false;
            this->description = description;
        }

        Node(int id, string description){
            this->accessible = false;
            this->id = id;
            this->description = description;
        }
        
        Node(int id, string description, bool accessible){
            this->accessible = accessible;
            this->id = id;
            this->description = description;
        }

        //Necessary function to serialize the object's fields in order to save and load it
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & id;
            ar & description;
            ar & items;
            ar & accessible_nodes;
            ar & accessible;
        }

        void setId(int id);
        void setDescription(string description);
        void addItem(Item *item);
        void addRoute(Node *n);
        void lock();
        void unlock();
        bool isAccessible();
};
}
