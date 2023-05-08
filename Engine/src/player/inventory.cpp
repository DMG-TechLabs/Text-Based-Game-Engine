#include "inventory.h"

#include <iostream>

using namespace std;

bool exists(vector<Item> vector, Item item);

// Getters
vector<Item> Inventory::getItems() { return items; }

Item Inventory::getItem(string id) {
    for (int i = 0; i < 32; i++) {
        if (items.at(i).getItemId() == id) {
            return items.at(i);
        }
    }
    return {};
}

int Inventory::getQuantity(Item item) {
    int count = 0;

    for (Item i : items) {
        if (i.getItemId() == item.getItemId()) count++;
    }
    return count;
}

int Inventory::getQuantity(string id) {
    int count = 0;

    for (Item i : items) {
        if (i.getItemId() == id) count++;
    }
    return count;
}

void Inventory::printInventory() {
    vector<Item> passed;
    for (Item i : items) {
        if (!exists(passed, i)){
            cout << "Name: " << i.getName() << ", Id: " << i.getItemId()
                 << ", Quantity: " << getQuantity(i) << endl;
        }
        passed.push_back(i);
    }
}

// For progress
string Inventory::exportContents() {
    return "inventory here";  // an doyleuei h synarthsh getStacks() logika
                              // aythn tha pairneis
}

void Inventory::importContents() {}

// Utils

bool exists(vector<Item> vector, Item item) {
    for (size_t i = 0; i < vector.size(); i++) {
        if(vector.at(i).getItemId() == item.getItemId()) return true;
    }

    return false;
}