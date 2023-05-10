#pragma once

#include <iostream>
#include <string>

#include "../item/item.h"

using namespace std;

struct Response{
    string command;
    vector<string> args;
};


Response prompt(char prompt_char, string accepted_commands[], vector<string> game_commands = {});
Response prompt(char prompt_char, string message, string accepted_commands[], vector<string> game_commands = {});

void print(string message);
void print(int message);
void print(char message);

void println(string message);
void println(int message);
void println(char message);
