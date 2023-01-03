#include "Activities/Complaint.h"
#include "Systems/Report.h"
#include "Systems/InteractiveSystem.h"
#include "Systems/DispatchSystem.h"

using namespace std;

Complaint::Complaint(string content, Report* corReport):Activity(),ComplaintContent(content),
CommunicationRecord("空"){
    this->ActivityType = EActivityType::ComplaintType;
    this->CorReport = corReport;
}

Complaint::~Complaint(){

}

string Complaint::getComplaintContent(){
    return this->ComplaintContent;
}

void Complaint::setComplaintContent(string newComplaintContend){
    this->ComplaintContent = newComplaintContend;
}

string Complaint::getCommunicationRecord(){
    return this->CommunicationRecord;
}

void Complaint::setCommunicationRecord(string newCommunicationRecord){
    this->CommunicationRecord = newCommunicationRecord;
}

const map<string, string>& Complaint::getSituationExplain(){
    return this->SituationExplain;
}

void Complaint::insertSituationExplain(string workerID, string explain){
    this->SituationExplain.insert(pair<string, string>(workerID, explain));
}

void Complaint::eraseSituationExplain(string workerID){
    this->SituationExplain.erase(workerID);
}

// void Complaint::getRelatePersonID(set<string>& ret){
//     auto activityList = this->CurReport->getActivityList();
//     for(auto &i : activityList){
//         i.getActivityType()==
//     }
// }

void Complaint::activityStart(){
    set<string> relatedIDs;
    this->CorReport->getRelatePersonID(relatedIDs);
    InteractiveSystem* interactiveSystemInstance = InteractiveSystem::getInstance();
    DispatchSystem* DispatchSystemInstance = DispatchSystem::getInstance();

    for(auto &i : relatedIDs){
        string explain = interactiveSystemInstance->getMockSituationExplain(i);
        this->insertSituationExplain(i, explain);

        Worker* relatedWorker = DispatchSystemInstance->getWorkerByID(i);
        if(relatedWorker != nullptr){
            relatedWorker->addActivityIDList(this->getID());
        }
    }

}


void Complaint::activityExecute(){
    // this->curReport
    InteractiveSystem* interactiveSystemInstance = InteractiveSystem::getInstance();
    this->setCommunicationRecord(interactiveSystemInstance->getMockCommunicationRecord()); 

}

void Complaint::activityFinished(){
    set<string> relatedIDs;
    this->CorReport->getRelatePersonID(relatedIDs);
    DispatchSystem* DispatchSystemInstance = DispatchSystem::getInstance();
    for(auto &i : relatedIDs){
        Worker* relatedWorker = DispatchSystemInstance->getWorkerByID(i);
        if(relatedWorker != nullptr){
            relatedWorker->removeActivityIDList(this->getID());
        }
    }
}

