#pragma once
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;
typedef void (*callback_function)(void);

class Threads{
    private:

    public:
        vector<thread*> threads_list;
        Threads(){}
        ~Threads(){}

        template <typename T, typename... Args>
        inline T createThread(callback_function func, T *output, Args... args);  //{return n + sum(args...);}

        // void createThread(void *function,  ,auto *output);

        vector<thread*> getThreadsList();
        void setThreadsList(thread thread_lits);
        thread getThreadAt(int i);
        void joinThread(int i);
        void joinAllThreads();
        void getThreadId(int i);
};

    // std::cout << boost::this_thread::get_id() << '\n';
    // std::cout << boost::thread::hardware_concurrency() << '\n';
    // boost::thread::attributes attrs;
    // attrs.set_stack_size(1024);
    // boost::thread t{attrs, thread};
    // t.join();

// The finction to be passed must have a point which the return value to be passed
// function to be used in callable  
// void func_dummy(int N, int *out)  
// {  
//     using namespace std::chrono_literals;
//     for (int i = 0; i < N; i++) {  
//         std::cout << "Thread id : " << std::this_thread::get_id() << std::endl;  
//         std::this_thread::sleep_for(1000ms);
//     }
//     out = 5;
// }  


// int *out = new int(1);
//     std::thread th1(func_dummy, 1, out);
//     // std::thread th2(func_dummy, 4);
//     // std::thread th3(func_dummy, 4);
//     th1.join();
//     // th2.join();
//     // th3.join();
//     std::cout << *out << std::endl;