#include "prompt.h"

#include <iostream>
#include <string>
#include <unistd.h>

#include "../command/command.h"
#include "../item/item.h"
#include "../text/text.h"

using namespace Engine;

/* ============={Utils}============= */
namespace PromptUtils{

bool contains(string *arr, string str) {
    int size = 0;
    while (!arr[size].empty()) ++size;

    bool exists = false;
    for (int i = 0; i < size; i++) {
        if (str == arr[i]) {
            exists = true;
            break;
        }
    }

    return exists;
}

bool contains(vector<string> arr, string str) {
    bool exists = false;
    for (int i = 0; i < arr.size(); i++) {
        if (str == arr.at(i)) {
            exists = true;
            break;
        }
    }

    return exists;
}

int itemsLength(Item **items) {
    int length_counter = 0;
    while (items[length_counter]) length_counter++;

    return length_counter;
}
}

/* ============={End of Utils}============= */


Response Engine::prompt(Prompt p, vector<string> game_commands, bool displayPrompt){
    if(displayPrompt)
        return Engine::prompt(p.prompt_char, p.message, p.accepted_commands, game_commands);
    else
        return Engine::prompt(p.prompt_char, "", p.accepted_commands, game_commands);

}

Response Engine::prompt(char prompt_char, vector<string> accepted_commands, vector<string> game_commands) {
    return Engine::prompt(prompt_char, "", accepted_commands, game_commands);
}

Response Engine::prompt(char prompt_char, string message, vector<string> accepted_commands, vector<string> game_commands) {
    string input, command;
    string *ret = new string[5]{"", "", "", "", ""};

    if (message != "") Engine::println(message, 1);
    cout << '\n' << Text::red <<  prompt_char << Text::normal <<  " ";

    getline(cin, input);

    int counter = 0, from = 0;
    for (int i = 0; i <= input.length(); i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            ret[counter++] = input.substr(from, i - from);
            from = i + 1;
        }
    }

    command = ret[0];
    bool is_acceptable;
    if(game_commands.size() != 0){
        // Check if command is garbage
        is_acceptable = PromptUtils::contains(game_commands, command);
        if (!is_acceptable) {
            println("Invalid command");
            return {};
        }
    }
    // Check if command is accepted
    is_acceptable = PromptUtils::contains(accepted_commands, command);
    if (!is_acceptable) {
        println("You can't do that here");
        return {};
    }

    cout << endl << endl;

    vector<string> args;
    for(int i = 1; i < 5; i++){
        if(ret[i] != "")
            args.push_back(ret[i]);
    }

    Response response{ret[0], args};
    return response;
}

void Engine::print(string message) { cout << message; }
void Engine::print(int message) { cout << message; }
void Engine::print(char message) { cout << message;}

void Engine::println(string message, int delay) {
    cout << message << endl; 
    sleep(delay);
}
void Engine::println(int message) { cout << message << endl; }
void Engine::println(char message) { cout << message << endl; }

