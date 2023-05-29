#pragma once

#include <string>
#include <vector>  
#include "../boost_serialization_includes.h"

using namespace std;

namespace Engine{

class Item {
    private:
        //Necessary to have access the serialization library
        friend class boost::serialization::access;

        string name;
        string item_id;    
        string description;
        
    public:
        //Constructors
        virtual ~Item(){}
        Item(){}

        Item(string name){
            this -> name = name;
        }

        Item(string name, string description){
            this -> name = name;
            this -> description = description;
        }

        Item(string item_id, string name, string description){
            this ->item_id = item_id;
            this -> name = name;
            this -> description = description;
        }


        //Necessary function to serialize the object's fields in order to save and load it
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & name;
            ar & item_id;
            ar & description;
        }

        //Setters getters
        void setName(string name);
        string getName();

        void setItemId(string item_id);
        string getItemId();

        void setDescription(string description);
        string getDescription();   
};


}