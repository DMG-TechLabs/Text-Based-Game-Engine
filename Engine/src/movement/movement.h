#pragma once

#include "../map/node.h"
#include "../player/player.h"

/**
 * @brief Method that moves player to a new node if it is accessible
 * 
 * @param currentNode The node the player is in
 * @param newNode The node the player tries to move to
 * @param player The player object
 */
void moveNode(Node *newNode, Player *player);

