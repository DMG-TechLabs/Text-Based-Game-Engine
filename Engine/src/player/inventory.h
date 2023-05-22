#pragma once

#include "../item/item.h"
#include "../boost_serialization_includes.h"

using namespace std;

/**
 * @brief Inventory class
 * 
 */
class Inventory {
    private:
        //Necessary to have access the serialization library
        friend class boost::serialization::access;
        vector<Item> items;

    public:
        Inventory(){};
        ~Inventory(){};
        Inventory(vector<Item> items){
            this->items = items;
        };

        //Necessary function to serialize the object's fields in order to save and load it
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & items;
        }
        
        //Getters
        vector<Item> getItems();
        void addItem(Item item);

        //Auxilary methods
        Item getItem(string id);
        int getQuantity(Item item);
        int getQuantity(string id);
        
        //For progress
        string exportContents();
        void importContents();

        void printInventory();
};