#include "game_utils.h"
#include <vector>

using namespace Engine;

void saveToFile(string file_name, string text_data){
    ofstream file;
    file.open (file_name);
    file << text_data;
    file.close();
}

string loadFromFile(string file_name){
    string text_data;
    ifstream file;
    file.open (file_name);
    file >> text_data;
    file.close();

    return text_data;
}

template <typename T> 
void saveObject(string filename, T object_to_save)
{
    ofstream outfile;
    outfile.open(filename, ios::binary | ios::out);
    outfile.write(&object_to_save, sizeof(object_to_save));
    return;
}

template <typename T> 
T loadObject(string filename, T object_to_load)
{
    ifstream infile;
    infile.open("silly.dat", ios::binary | ios::in);
    infile.read(&object_to_load, sizeof(object_to_load));
    return object_to_load;
}
