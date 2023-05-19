#include <unistd.h>  // for sleep()

#include <iostream>
#include <string>

#include "engine.h"

using namespace std;
using namespace Engine;

int main(int argc, char *argv[]) {
    cout << "Main" << endl;

    Inventory i{};

    i.addItem(new Item{"1", "Note", "A note"});
    i.addItem(new Item{"2", "Terminal", "A terminal"});
    i.addItem(new Item{"1", "Note", "A note"});
    i.addItem(new Item{"2", "Terminal", "A terminal"});
    i.addItem(new Item{"1", "Note", "A note"});
    i.addItem(new Item{"2", "Terminal", "A terminal"});
    i.addItem(new Item{"1", "Note", "A note"});
    i.addItem(new Item{"2", "Terminal", "A terminal"});
    i.addItem(new Item{"3", "Book", "A book"});

    Node *n1 = new Node(1, "Room one");
    Node *n2 = new Node(2, "Room two");

    n1->addRoute(n2);
    n1->unlock();
    n2->unlock();
    Player p{i, "Mpamphs", vector<int>{10, 10, 10}, n1};


    p.moveToNode(n2);
    cout << p.currentNode->id << endl;

    p.getInventory().printInventory();
    vector<string> gc{"help", "enter", "read", "save"};
    Response r = prompt('>', "The room you are in has the number one on the door. The hallway connects the rooms one and two", vector<string>{"help", "enter"}, gc);

    

    return 0;
}
