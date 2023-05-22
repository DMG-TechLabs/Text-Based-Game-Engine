#pragma once

#include <string>
// #include <unordered_map>
// #include <ctime>
// #include <bits/stdc++.h>

#include "../player/player.h"
#include "../achievements/achievement.h"
#include "../node/node.h"
// #include "../player/inventory.h"
// #include "../utils/game_utils.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;

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
        friend class boost::serialization::access;
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
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & player;
            ar & nodes;
            ar & achievements;
        }

};