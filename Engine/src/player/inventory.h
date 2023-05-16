#pragma once

#include "../item/item.h"

using namespace std;

namespace Engine{

/**
 * @brief Inventory class
 * 
 */
class Inventory {
    private:
        vector<Item> items;

    public:
        Inventory(){};
        ~Inventory(){};
        Inventory(vector<Item> items){
            this->items = items;
        };
        
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
}