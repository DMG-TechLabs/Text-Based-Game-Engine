#pragma once

#include "../engine.h"

class Objective{
    private:
        string description;
        bool completed = false;
    
    public:
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