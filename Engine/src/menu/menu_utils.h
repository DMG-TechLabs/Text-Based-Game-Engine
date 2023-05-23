#pragma once

#include <iostream>
#include <string>

using namespace std;

string addSpaces(string word, int length);
void printOption(int selectedItem, int index, int color, string option);
void disableInputBuffering();
void enableInputBuffering();
int handleKeys();