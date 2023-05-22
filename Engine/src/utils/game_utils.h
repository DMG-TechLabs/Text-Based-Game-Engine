#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "../progress/progress.h"

using std::ofstream;
using std::ifstream;

using namespace std;

void saveToFile(string file_name, string text_data);

string loadFromFile(string file_name);

// template <typename T> 
// void saveObject(string filename, T object_to_save);

// template <typename T> 
// T loadObject(string filename);

void saveProgress(Progress progress, string filename);

Progress loadProgress(string filename);

//void ThreadworkerFunc();