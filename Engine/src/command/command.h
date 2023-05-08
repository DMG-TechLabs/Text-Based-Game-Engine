#pragma once

#include <array>
#include <cstdarg>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdarg>
#include "../item/item.h"
#include "../player/player.h"
#include "../node/node.h"
#include "../utils/prompt.h"
#include "../utils/game_utils.h"

#include "../item/item.h"
#include "../map/node.h"
#include "../player/player.h"
#include "../utils/game_utils.h"
#include "../utils/prompt.h"

#define MAX_ROOMS 5

using namespace std;

namespace Engine {
    class Command{
    public:
        string name;

        ~Command() {}
        Command(){}
        Command(string name) { this->name = name; }

        void run();
        void run(string command);
        void run(string command, Item* item);
        void run(Item *item);
        void run(string command, Player *player, Node *room);
        void run(string command, Player *player, Item *item);
    };
}  // namespace Engine