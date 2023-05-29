#include "threads.h"

vector<thread*> Threads::getThreadsList(){
    return this->threads_list;
}

template <typename T, typename... Args>
inline T Threads::createThread(callback_function func, T *output, Args... args){
    cout << "yes";
    return output;
}