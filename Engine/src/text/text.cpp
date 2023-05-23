#include "text.h"

#include <chrono>
#include <thread>
#include <stdlib.h>

#include "../utils/prompt.h"

using namespace Engine;


const string Text::normal = "\e[0;39m";
const string Text::bold = "\e[1m";
const string Text::underline = "\033[4m";
const string Text::italic = "\e[3m";

const string Text::clear = "\e[2J";
const string Text::erase_line = "\e[2K";

const string Text::black = "\e[0;30m";
const string Text::red = "\e[0;31m";
const string Text::green = "\e[0;32m";
const string Text::yellow = "\e[0;33m";
const string Text::blue = "\e[0;34m";
const string Text::purple = "\e[0;35m";
const string Text::cyan = "\e[0;36m";
const string Text::lgrey = "\e[0;37m";
const string Text::dgrey = "\e[0;38m";

const string Text::u_black = "\e[4;30m";
const string Text::u_red = "\e[4;31m";
const string Text::u_green = "\e[4;32m";
const string Text::u_yellow = "\e[4;33m";
const string Text::u_blue = "\e[4;34m";
const string Text::u_purple = "\e[4;35m";
const string Text::u_cyan = "\e[4;36m";
const string Text::u_lgrey = "\e[4;37m";
const string Text::u_dgrey = "\e[4;38m";

const string Text::b_black = "\e[1;30m";
const string Text::b_red = "\e[1;31m";
const string Text::b_green = "\e[1;32m";
const string Text::b_yellow = "\e[1;33m";
const string Text::b_blue = "\e[1;34m";
const string Text::b_purple = "\e[1;35m";
const string Text::b_cyan = "\e[1;36m";
const string Text::b_lgrey = "\e[1;37m";
const string Text::b_dgrey = "\e[1;38m";

string Text::color(string where, int color) {
    if (where != "bg" && where != "fg") return "";
    if (color < 0 || color > 255) return "";

    return (where == "bg") ? "\e[48;5;" + to_string(color) + "m"
                           : "\e[38;5;" + to_string(color) + "m";
}

void Text::delayedTyping(string text) {
    int min_speed = 100;
    for (const auto c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(min_speed + rand() % min_speed));
    }
    std::cout << std::endl;
}

void Text::clearScreen() {
#ifdef _WIN32
    system("cls"); // Clear screen for Windows
#else
    system("clear"); // Clear screen for Linux and macOS
#endif
}
