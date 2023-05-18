#pragma once

#include <iostream>
#include <string>
#include <fstream>


using std::ofstream;
using std::ifstream;

using namespace std;

namespace Engine{


void saveToFile(string file_name, string text_data);

string loadFromFile(string file_name);

template <typename T> 
void saveObject(string filename, T object_to_save);

template <typename T> 
T loadObject(string filename, T object_to_load);

//void ThreadworkerFunc();
}