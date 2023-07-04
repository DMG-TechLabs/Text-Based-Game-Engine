#pragma once

#include <string>
#include <vector>

using namespace std;

namespace Engine{
    void menu(string title, int bgColor, vector<string> options, void (*handleOptionsFunc)(int selectedOption));
}