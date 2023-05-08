#include "node.h"

void Node::lock(){
    this->accessible = false;
}

void Node::unlock(){
    this->accessible = true;
}

bool Node::isAccessible(){
    return accessible;
}