#include "Activities/Maintain.h"

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
    this->MaintainRecord.WorkerID = WorkerID;
}

string Maintain::getMaintainDescription(){
    return this->MaintainRecord.MaintainDescription;
}

void Maintain::setMaintainDescription(string newMaintainDescription){
    this->MaintainRecord.MaintainDescription = MaintainDescription;
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

void Maintain::setMaintainEndTime(time_t newMaintainStartTime){
    this->MaintainRecord.MaintainStartTime = newMaintainStartTime;
}

Report* Maintain::getCorReport(){
    return this->CorReport;
}

void Maintain::setCorReport(Report* newCorReport){
    this->CorReport = newCorReport;
}

void Maintain::activityStart(){

}

void Maintain::activityExecute(){

}

void Maintain::activityFinished(){

}


