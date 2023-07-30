#include "game_utils.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <filesystem>
#include <limits.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace Engine;


std::string Engine::getExecutablePath() {
#if defined(_WIN32)
    char buffer[MAX_PATH];
    GetModuleFileName(nullptr, buffer, MAX_PATH);
    return std::string(buffer);
#elif defined(__linux__) || defined(__APPLE__)
    char buffer[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1) {
        buffer[len] = '\0';
        return std::string(buffer);
    }
#endif
    return "";
}

bool Engine::saveToFile(string file_path, string content) {
	std::ofstream file(file_path);

	if (file.is_open()) {
		file << content;
		file.close();
		return true;
	} else {
		return false;
	}
}


string Engine::loadFromFile(string filepath) {
	string s = "";
	std::ifstream file(filepath);
	if (file.is_open()) {
		// Read data from the file and process it
		std::string line;
		while (std::getline(file, line)) {
			s += line + '\n';
		}
		file.close();
	} else {
		return "";
	}

	return s;
}

// template <typename T> 
// void Engine::saveObject(string filename, T object_to_save)
// {
//     ofstream ofs(filename);
//     {
//         boost::archive::text_oarchive oa(ofs);
//         // write class instance to archive
//         oa << object_to_save;
//     	// archive and stream closed when destructors are called
//     }
// }

// template <typename T> 
// T Engine::loadObject(string filename, T object_to_load)
// {
//     T object_to_load;
//     ifstream ifs(filename);
//     {
//         boost::archive::text_iarchive ia(ifs);
//         ia >> object_to_load;
//     }

//     return object_to_load;
// }

void Engine::saveProgress(Progress progress, string filename){
	/*
	   ofstream ofs(filename);
	   {
	   boost::archive::text_oarchive oa(ofs);
	// write class instance to archive
	oa << progress;
	// archive and stream closed when destructors are called
	}
	*/ 
}

Progress Engine::loadProgress(string filename){
	/*
	   Progress loaded_progress;
	   ifstream ifs(filename);
	   {
	   boost::archive::text_iarchive ia(ifs);
	   ia >> loaded_progress;
	   }

	   return loaded_progress;
	   */
}

// void thr(){
//     boost::posix_time::seconds workTime(5);
//     boost::this_thread::sleep(workTime)


// }
//
//


bool Engine::deleteFile(string path){
	if (std::remove(path.c_str()) != 0) {
		perror("Error deleting file");
		return false;
	}

	return true;
}

string Engine::getProjectPath(){
	std::string executablePath = getExecutablePath();
	size_t lastSeparatorPos = executablePath.find_last_of("\\/");
	if (lastSeparatorPos != std::string::npos) {
		return executablePath.substr(0, lastSeparatorPos);
	}

	return "";
}

