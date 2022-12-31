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

string InteractiveSystem::getMockCommunicationRecord(){
    return this->MockCommunicationRecord;
}

time_t InteractiveSystem::getMockMaintainStartTime(){
    return this->MockMaintainStartTime;
}

string InteractiveSystem::getMockMaintainDescription(){
    return this->MockMaintainDescription;
}


void InteractiveSystem::getMockMaintainEndEvent(std::time_t & retEndTime, EMaintainFlag& retFlag){
    retEndTime = MockMaintainEndTime;
    retFlag = MaintainEndFlag;
}

EFaultType InteractiveSystem::getMockFaultType(){
    return this->MockFaultType;
}

std::string InteractiveSystem::getMockDispatcherID(){
    return this->MockDispatcherID;
}
