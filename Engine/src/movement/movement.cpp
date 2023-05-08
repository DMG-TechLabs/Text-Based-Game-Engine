#include "movement.h"

/**
 * @brief Method that moves player to a new node if it is accessible
 * 
 * @param currentNode The node the player is in
 * @param newNode The node the player tries to move to
 * @param player The player object
 */
void moveNode(Node *newNode, Player *player){
    
    /**
     * @brief If player tries to go to an inaccessible node, it will print the newNode description.
     */
    if (newNode->accesible == false)
    {
        print(newNode -> description);
    }

    /**
     * @brief If the player tries to enter an accessible node, it marks the current node as not inside and the new node as inside
     *        it also changes the currentNode parameter inside the player object to the new one. Finally it prints the new node  
     */
    else{
        player->currentNode = newNode;
        print(newNode -> description);
    }

}