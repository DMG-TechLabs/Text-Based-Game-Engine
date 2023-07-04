#include "../engine.h"
#include "./menu.h"
#include "./menu_utils.h"

#include <iostream>

void Engine::menu(string title, int bgColor, vector<string> options, void (*handleOptionsFunc)(int selectedOption)){
    disableInputBuffering();

    int numOfOptions = options.size();

    int max = title.size() / 2 + 2;
    int selectedItem = 0;
    bool menuActive = true;

    // Add the necessary spaces
    for(int i = 0; i < options.size(); i++){
        options.at(i) = addSpaces(options.at(i), max);
    }

    while (menuActive) {
        Engine::Text::clearScreen();

        cout << title << endl;

        // Print the options
        for (int i = 0; i < numOfOptions; i++){
            printOption(selectedItem, i, bgColor, options.at(i));
        }
        
        // Handle user input
        int keyPressed = handleKeys();
        switch (keyPressed) {
            case 1: // Up arrow key
                selectedItem = (selectedItem == 0) ? numOfOptions-1 : selectedItem - 1;
                break;
            case 2: // Down arrow key
                selectedItem = (selectedItem == numOfOptions-1) ? 0 : selectedItem + 1;
                break;
            case 0: // Enter
                menuActive = false;
                Engine::Text::clearScreen();
                handleOptionsFunc(selectedItem);
                break;
        }

    }
    enableInputBuffering();
}