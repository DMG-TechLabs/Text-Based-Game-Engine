#pragma once

#include <string>
#include <vector>  

using namespace std;

namespace Engine{

class Item {
    private:
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


        //Setters getters
        void setName(string name);
        string getName();

        void setItemId(string item_id);
        string getItemId();

        void setDescription(string description);
        string getDescription();   
};


}