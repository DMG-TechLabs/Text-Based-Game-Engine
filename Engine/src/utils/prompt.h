#pragma once

#include <iostream>
#include <string>

#include "../item/item.h"

using namespace std;

namespace Engine{

struct Response{
    string command;
    vector<string> args;
};

struct Prompt{
    char prompt_char;
    string message;
    vector<string> accepted_commands;
};

Response prompt(char prompt_char, string message, vector<string> accepted_commands, vector<string> game_commands = {});
Response prompt(Prompt p, vector<string> game_commands = {}, bool displayPromptMsg = true);

void print(string message);
void println(string message, int delay = 2);

}