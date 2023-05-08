#include <unistd.h>  // for sleep()

#include <iostream>
#include <string>

#include "engine.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Main" << endl;

    Inventory i{};

    i.addItem(Item{"1", "Note", "A note"});
    i.addItem(Item{"2", "Terminal", "A terminal"});
    i.addItem(Item{"1", "Note", "A note"});
    i.addItem(Item{"2", "Terminal", "A terminal"});
    i.addItem(Item{"1", "Note", "A note"});
    i.addItem(Item{"2", "Terminal", "A terminal"});
    i.addItem(Item{"1", "Note", "A note"});
    i.addItem(Item{"2", "Terminal", "A terminal"});
    i.addItem(Item{"3", "Book", "A book"});

    Node *n1 = new Node(1, "Room one");
    Node *n2 = new Node(2, "Room two");

    n1->addRoute(n2);
    n1->unlock();
    n2->unlock();
    Player p{i, "Mpamphs", vector<string>{"help", "enter", "read"}, vector<int>{10, 10, 10}, n1};


    p.moveToNode(n2);
    cout << p.currentNode->id << endl;

    p.getInventory().printInventory();

    

    

    return 0;
}
