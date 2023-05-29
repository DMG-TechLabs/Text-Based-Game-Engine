#include "game_utils.h"


using namespace Engine;

void Engine::saveToFile(string file_name, string text_data){
    ofstream file;
    file.open (file_name);
    file << text_data;
    file.close();
}

string Engine::loadFromFile(string file_name){
    string text_data;
    ifstream file;
    file.open (file_name);
    file >> text_data;
    file.close();

    return text_data;
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
    ofstream ofs(filename);
    {
        boost::archive::text_oarchive oa(ofs);
        // write class instance to archive
        oa << progress;
    	// archive and stream closed when destructors are called
    }
}

Progress Engine::loadProgress(string filename){
    Progress loaded_progress;
    ifstream ifs(filename);
    {
        boost::archive::text_iarchive ia(ifs);
        ia >> loaded_progress;
    }

    return loaded_progress;
}

// void thr(){
//     boost::posix_time::seconds workTime(5);
//     boost::this_thread::sleep(workTime)


// }
