#pragma once

#include <array>
#include <cstdarg>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdarg>

#include "../player/player.h"
#include "../utils/prompt.h"

using namespace std;

namespace Engine {
    class Command{
    public:
        static bool run(Response response, Prompt p, Player *player);
    };
}  // namespace Engine