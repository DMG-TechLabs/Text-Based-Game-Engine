#include "node.h"

void Node::lock() { this->accessible = false; }

void Node::unlock() { this->accessible = true; }

bool Node::isAccessible() { return accessible; }

void Node::setId(int id) { this->id = id; }

void Node::setDescription(string description) {
    this->description = description;
}

void Node::addRoute(Node *n) { accessible_nodes.push_back(n); }

void Node::addItem(Item item) { this->items.push_back(item); }