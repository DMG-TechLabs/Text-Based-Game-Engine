#include "objective.h"

#include "../../engine.h"
#include <string>

using namespace CliKit;

void Objective::setDescription(string description) {
    this->description = description;
}

string Objective::getDescription() { return description; }

void Objective::setStatus(bool completed) { this->completed = completed; }

bool Objective::isCompleted() { return completed; }

void Objective::printObjectives(vector<Objective *> objectives) {
    Engine::println("\n-" + Text::yellow + "Current Objectives" + Text::normal + "-");
    for (int i = 0; i < objectives.size(); i++) {
        (objectives.at(i)->isCompleted()) ? Engine::println(Text::green + to_string(i+1) + ". " + objectives.at(i)->getDescription() + Text::normal, 1)
                                          : Engine::println(Text::red + to_string(i+1) + ". " + objectives.at(i)->getDescription() + Text::normal, 1);
    }
    Engine::println("", 0);
}

bool Objective::completeObjective(bool check, vector<Objective *> objectives, int index){
    if(
        check && 
        objectives.at(index)->parent != nullptr && 
        !objectives.at(index)->parent->isCompleted() 
    ){
        cout << "First complete: " << objectives.at(index)->parent->getDescription() << endl;
        return false;
    }

    if(check) {
		objectives.at(index)->setStatus(Objective::COMPLETED);
		return true;
	}

	return false;
}

    
