#pragma once

#include "objective.h"
#include <vector>

/**
 * @brief Mission class
 * 
 */
class Mission{
    private:
        string name;
        string description;
        bool completed = false;

    public:
        vector<Objective *> objectives;
        static const bool COMPLETED = true;

        Mission(){}
        ~Mission(){}
        
        Mission(string name, string description, vector<Objective *> objectives){
            this->name = name;
            this->description = description;
            this->objectives = objectives;
        }

        void setName(string name);
        string getName();

        void setDescription(string description);
        string getDescription();

        void setStatus(bool completed);
        bool isCompleted();
}; 
