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

    i.printInventory();
    return 0;
}
