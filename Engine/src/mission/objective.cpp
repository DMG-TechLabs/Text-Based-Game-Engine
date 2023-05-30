#include "objective.h"

#include "../engine.h"

void Objective::setDescription(string description) {
    this->description = description;
}

string Objective::getDescription() { return description; }

void Objective::setStatus(bool completed) { this->completed = completed; }

bool Objective::isCompleted() { return completed; }

void Objective::printObjectives(vector<Objective *> objectives) {
    Engine::println("\n-" + Engine::Text::yellow + "Current Objectives" + Engine::Text::normal + "-");
    for (int i = 0; i < objectives.size(); i++) {
        (objectives.at(i)->isCompleted()) ? Engine::println(Engine::Text::green + objectives.at(i)->getDescription() + Engine::Text::normal, 1)
                                          : Engine::println(Engine::Text::red + objectives.at(i)->getDescription() + Engine::Text::normal, 1);
    }
    Engine::println("", 0);
}

void Objective::completeObjective(bool check, vector<Objective *> objectives, int index){
    if(check) objectives.at(index)->setStatus(Objective::COMPLETED);
}