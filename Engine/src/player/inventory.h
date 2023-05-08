#pragma once

#include "../item/item.h"

using namespace std;

/**
 * @brief Inventory class
 * 
 */
class Inventory {
    private:
        // Item* inventory[32];
        // vector<Item> items;
        
    public:
        vector<Item> items;
        //Constructors 
        Inventory(){};
        ~Inventory(){};
        Inventory(vector<Item> items){
            this->items = items;
        };
        
        //Getters
        vector<Item> getItems();
        void addItem(Item item){
            items.push_back(item);
        }

        //Auxilary methods
        Item getItem(string id);
        int getQuantity(Item item);
        int getQuantity(string id);
        
        //For progress
        string exportContents();
        void importContents();

        void printInventory();
};