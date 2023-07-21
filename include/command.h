#pragma once

#include "player.h"
#include "prompt.h"

#include <array>
#include <cstdarg>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdarg>

using namespace std;

namespace Engine {
    class Command{
    public:
        static bool run(Response response, Prompt p, Player *player);
    };
}  // namespace Engine
