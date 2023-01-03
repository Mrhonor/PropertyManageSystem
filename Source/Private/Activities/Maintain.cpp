#include "Activities/Maintain.h"
#include "Systems/InteractiveSystem.h"
#include "Systems/PerformanceSystem.h"
#include "Systems/DispatchSystem.h"
#include "Systems/Report.h"

using namespace std;

Maintain::Maintain(string dispatcherID, string workerID, Report* corReport):Activity(), CorReport(corReport){
    this->MaintainRecord.DispatcherID = dispatcherID;
    this->MaintainRecord.WorkerID = workerID;
    this->ActivityType = EActivityType::MaintainType;
}


Maintain::~Maintain(){

}

string Maintain::getDispatcherID(){
    return this->MaintainRecord.DispatcherID;
}

void Maintain::setDispatcherID(string newDispatcherID){
    this->MaintainRecord.DispatcherID = newDispatcherID;
}

string Maintain::getWorkerID(){
    return this->MaintainRecord.WorkerID;
}

void Maintain::setWorkerID(string newWorkerID){
    this->MaintainRecord.WorkerID = newWorkerID;
}

string Maintain::getMaintainDescription(){
    return this->MaintainRecord.MaintainDescription;
}

void Maintain::setMaintainDescription(string newMaintainDescription){
    this->MaintainRecord.MaintainDescription = newMaintainDescription;
}

time_t Maintain::getMaintainStartTime(){
    return this->MaintainRecord.MaintainStartTime;
}

void Maintain::setMaintainStartTime(time_t newMaintainStartTime){
    this->MaintainRecord.MaintainStartTime = newMaintainStartTime;
}

time_t Maintain::getMaintainEndTime(){
    return this->MaintainRecord.MaintainEndTime;
}

void Maintain::setMaintainEndTime(time_t newMaintainEndTime){
    this->MaintainRecord.MaintainEndTime = newMaintainEndTime;
}

Report* Maintain::getCorReport(){
    return this->CorReport;
}

void Maintain::setCorReport(Report* newCorReport){
    this->CorReport = newCorReport;
}

TMaintainRecord Maintain::getMaintainRecord(){
    return this->MaintainRecord;
}

time_t Maintain::getLaborHour(){
    return this->MaintainRecord.MaintainEndTime - this->MaintainRecord.MaintainStartTime;
}

void Maintain::activityStart(){
    InteractiveSystem* interactiveSystemInstance = InteractiveSystem::getInstance();
    this->setMaintainStartTime(interactiveSystemInstance->getMockMaintainStartTime());

}

void Maintain::activityExecute(){
    InteractiveSystem* interactiveSystemInstance = InteractiveSystem::getInstance();
    this->setMaintainDescription(interactiveSystemInstance->getMockMaintainDescription());
}

void Maintain::activityFinished(){
    InteractiveSystem* interactiveSystemInstance = InteractiveSystem::getInstance();
    PerformanceSystem* PerformanceSystemInstance = PerformanceSystem::getInstance();
    DispatchSystem* DispatchSystemInstance = DispatchSystem::getInstance();
    EMaintainFlag eventFlag;
    time_t endTime;
    interactiveSystemInstance->getMockMaintainEndEvent(endTime, eventFlag);

    Worker* tarWorker = DispatchSystemInstance->getWorkerByID(this->getWorkerID());
    this->setMaintainEndTime(endTime);
    switch (eventFlag)
    {
        case EMaintainFlag::FaultTypeWrong:
        {
            EFaultType newFaultType = interactiveSystemInstance->getMockFaultType();
            this->CorReport->setFaultType(newFaultType);
            
            string dispatcherID = interactiveSystemInstance->getMockDispatcherID();
            DispatchSystemInstance->Dispatch(dispatcherID, *this->CorReport);
            DispatchSystemInstance->updateWorkerState(this->getWorkerID(), EWorkerState::Idle);
            break;
        }
        case EMaintainFlag::Unfinish:
        {
            Maintain* newMaintain = new Maintain(getDispatcherID(), getWorkerID(), getCorReport());

            this->CorReport->insertActivity(newMaintain);
            tarWorker->setCurMaintain(newMaintain);
            break;
        }
        case EMaintainFlag::Normal:
        {
            
            tarWorker->setCurState(EWorkerState::Idle);
            tarWorker->setCurMaintain(nullptr);
            break;
        }

    }
    tarWorker->removeActivityIDList(this->getID());
    PerformanceSystemInstance->addWorkerLaborHour(getWorkerID(), getLaborHour());
}


