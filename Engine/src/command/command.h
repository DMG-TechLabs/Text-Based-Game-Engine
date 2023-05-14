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
        static void run();
        static void run(string command);
        static void run(string command, Item item);
        static void run(Item item);
        static void run(string command, Player *player, Node *room);
        static void run(string command, Player *player, Item item);
        static void run(Response response, Prompt p, Player *player);
    };
}  // namespace Engine