#pragma once

#include <string>
#include <vector>

using namespace std;

namespace Engine{
    void menu(int bgColor, vector<string> options, void (*handleOptionsFunc)(int selectedOption));
}