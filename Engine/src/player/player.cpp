#include "player.h"
#include "inventory.h"

//Setters getters
void Player::setInventory(Inventory inventory){
    this -> inventory = inventory;
}

Inventory Player::getInventory(){
    return inventory;
}

void Player::setName(string name){
    this -> name = name;
}

string Player::getName(){
    return name;
}

vector<int> Player::getStats(){
    return stats;
}
void Player::setCurrentNode(Node *newNode){
    this->currentNode = newNode;
}

bool exists(vector<Node*> vector, Node *node) {
    for (size_t i = 0; i < vector.size(); i++) {
        if(vector.at(i)->id == node->id) return true;
    }

    return false;
}

/**
 * @brief Method that moves player to a new node if it is accessible
 * 
 * @param currentNode The node the player is in
 * @param newNode The node the player tries to move to
 * @param player The player object
 */
void Player::moveToNode(Node *newNode) {
    if(!exists(this->currentNode->accessible_nodes, newNode)) return; // if the new node is not accessible from the current node return (to avoid jumps)
    /**
     * @brief If player tries to go to an inaccessible node, it will print the newNode description.
     */
    if (!newNode->isAccessible()) {
        print(newNode -> description);
    }
    /**
     * @brief If the player tries to enter an accessible node, it changes the currentNode parameter inside the player object to the new one. Finally it prints the new node  
     */
    else {
        this->currentNode = newNode;
        print(newNode -> description);
    }

}

void Player::addCommand(string command){
    this->commands.push_back(command);
}

void Player::collectItem(Item item){
    this->inventory.addItem(item);
}