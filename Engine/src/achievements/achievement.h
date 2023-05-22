#pragma once
#include <string>
#include <vector>
#include "../boost_serialization_includes.h"


using namespace std;


/**
 * @brief Achievement class
 * 
 */
class Achievement{
    private:
        bool unlocked = false;
        string name;
        string description;
        //Necessary to have access the serialization library
        friend class boost::serialization::access;

    public:
        ~Achievement(){};
        Achievement(){};
        Achievement(string name, string description){
            this->name = name;
            this->description = description;
        };

        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & unlocked;
            ar & description;
            ar & name;
        }

        //Setters getters
        void setName(string name);
        string getName();
        void setDescription(string name);
        string getDescription();
        void setUnlocked(bool unlocked);
        bool isUnlocked();

        //Methods
        void unlock();



};

