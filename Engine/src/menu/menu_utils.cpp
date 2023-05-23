
#ifdef _WIN32
    #include <conio.h>  
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#include <iostream>

#include "../engine.h"
#include "./menu.h"
#include "./menu_utils.h"

using namespace std;
using namespace Engine;


void enableInputBuffering(){
    #ifdef _WIN32
        // Enable console input buffering
        SetConsoleMode(hInput, mode);
    #else
        termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag |= (ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &term);

    #endif
    print("\e[?25h"); // Show the cursor
}

void disableInputBuffering(){
    #ifdef _WIN32
        // Disable console input buffering
        DWORD mode;
        HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(hInput, &mode);
        SetConsoleMode(hInput, mode & ~ENABLE_ECHO_INPUT & ~ENABLE_LINE_INPUT);
    #else
        termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &term);

    #endif
    print("\e[?25l"); // Hide the cursor
}

int handleKeys() {
    #ifdef _WIN32
        switch (_getch()) {
            case 13:  // Enter
                return 0;
            case 72:  // Up
                return 1;
            case 80:  // Down
                return 2;
            default:
                return -1;
        }
    #else
        switch (getchar()){
            case '\n': return 0;
            case 65: return 1;
            case 66: return 2;
            case 67: return 3;
            case 68: return 4;
            default: return -1;
        }
    #endif
}

string addSpaces(string word, int length) {
    if (length < word.size()) return "WRONG";

    while (word.size() < length) {
        word += " ";
    }
    return word;
}

void printOption(int selectedItem, int index, int color, string option) {
    std::cout << (selectedItem == index ? Engine::Text::color("bg", color) +
                                              option + Engine::Text::normal
                                        : option)
              << std::endl;
}