#pragma once

#include "progress.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
// #include <boost/archive/text_oarchive.hpp>
// #include <boost/archive/text_iarchive.hpp>

using std::ofstream;
using std::ifstream;

using namespace std;

namespace Engine{


bool saveToFile(string file_path, string content);

string loadFromFile(string file_name);

// template <typename T> 
// void saveObject(string filename, T object_to_save);

// template <typename T> 
// T loadObject(string filename);

void saveProgress(Progress progress, string filename);

Progress loadProgress(string filename);

//void ThreadworkerFunc();
bool deleteFile(string path);

std::string getExecutablePath();
std::string getProjectPath();

}

