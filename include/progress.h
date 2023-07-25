#pragma once

#include "player.h"
#include "achievement.h"
#include "node.h"
// #include "inventory.h"
// #include "game_utils.h"

#include <string>
// #include <boost/archive/text_oarchive.hpp>
// #include <boost/archive/text_iarchive.hpp>
// #include <boost/serialization/vector.hpp>
// #include <unordered_map>
// #include <ctime>
// #include <bits/stdc++.h>


using namespace std;
namespace Engine{

// class Save{
//     private:
//         unordered_map<std::string, std::string> createHashTable();
//         string hashToString();
//     public:
//         Inventory *inventory;
//         int day;
//         // AchievementCollection *ac;
//         Node *room;
//         unordered_map<std::string, std::string> hash;
        
//         ~Save(){}
//         Save(Inventory *inventory, int day, /*AchievementCollection *ac,*/ Node *room){
//             this->inventory = inventory;
//             this->day = day;
//             // this->ac = ac;
//             this->room = room;

//             this->hash = createHashTable();

//             // saveToFile("../saves/save_" + getCurrentDate() + ".txt", hashToString());
//         }
//         string getCurrentDate();
// };

class Progress{
    public:
        // friend class boost::serialization::access;
        Player player;
        vector<Node> nodes;
        vector<Achievement> achievements;
        Progress(Player player, vector<Node> nodes={}, vector<Achievement> achievements={}){
            this->player = player;
            this->nodes = nodes;
            this->achievements = achievements;
        }
        Progress(){}
        ~Progress(){}
        int day;
/*
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & player;
            ar & nodes;
            ar & achievements;
        }
 */

};
}
