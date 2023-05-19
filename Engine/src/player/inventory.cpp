#include "inventory.h"

#include <iostream>

using namespace Engine;

using namespace std;

bool exists(vector<Item> vector, Item item);

// Getters
vector<Item *> Inventory::getItems() { return items; }

Item Inventory::getItem(string id) {
    for (int i = 0; i < 32; i++) {
        if (items.at(i)->getItemId() == id) {
            return *items.at(i);
        }
    }
    return {};
}

int Inventory::getQuantity(Item *item) {
    int count = 0;

    for (Item *i : items) {
        if (i->getItemId() == item->getItemId()) count++;
    }
    return count;
}

int Inventory::getQuantity(string id) {
    int count = 0;

    for (Item *i : items) {
        if (i->getItemId() == id) count++;
    }
    return count;
}

// For progress
string Inventory::exportContents() {
    return "inventory here";  // an doyleuei h synarthsh getStacks() logika
                              // aythn tha pairneis
}

void Inventory::importContents() {}
void Inventory::addItem(Item *item) { items.push_back(item); }




// Utils
bool exists(vector<Item> vector, Item item) {
    for (size_t i = 0; i < vector.size(); i++) {
        if (vector.at(i).getItemId() == item.getItemId()) return true;
    }

    return false;
}
