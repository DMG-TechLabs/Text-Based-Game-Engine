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


Response prompt(char prompt_char, vector<string> accepted_commands, vector<string> game_commands = {});
Response prompt(char prompt_char, string message, vector<string> accepted_commands, vector<string> game_commands = {});
Response prompt(Prompt p, vector<string> game_commands = {}, bool displayPrompt = true);

void print(string message);
void print(int message);
void print(char message);

void println(string message, int delay = 2);
void println(int message);
void println(char message);

}