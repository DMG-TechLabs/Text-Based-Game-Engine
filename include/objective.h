#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Objective{
    private:
        string description;
        bool completed = false;
    
    public:
        static const bool COMPLETED = true;
        Objective *parent = nullptr;

        Objective(){}
        ~Objective(){}

        Objective(string description){
            this->description = description;
        }

        void setDescription(string description);
        string getDescription();

        void setStatus(bool completed);
        bool isCompleted();

        static void printObjectives(vector<Objective *> objectives);
        static void completeObjective(bool check, vector<Objective *> objectives, int index);
};
