#include "Systems/InteractiveSystem.h"

using namespace std;

InteractiveSystem* InteractiveSystem::Instance = nullptr;

InteractiveSystem* InteractiveSystem::getInstance(){
    if(Instance == nullptr){
        Instance = new InteractiveSystem();
    }
    return Instance;
}

string InteractiveSystem::getMockSituationExplain(string key){
    return this->MockSituationExplain[key];
}