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
#include "../node/node.h"
#include "../player/player.h"
#include "../utils/game_utils.h"
#include "../utils/prompt.h"

using namespace std;

namespace Engine {
    class Command{
    public:
        string name;

        virtual ~Command() {}
        Command(){}
        Command(string name) { this->name = name; }

        virtual void run();
        virtual void run(string command);
        virtual void run(string command, Item item);
        virtual void run(Item item);
        virtual void run(string command, Player player, Node *room);
        virtual void run(string command, Player player, Item item);
    };
}  // namespace Engine