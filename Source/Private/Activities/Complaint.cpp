#include "Activities/Complaint.h"
#include "Systems/Report.h"

using namespace std;

Complaint::Complaint(string content):Activity(),ComplaintContent(content),
CommunicationRecord("空"){
    this->ActivityType = EActivityType::ComplaintType;
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

    
}


void Complaint::activityExecute(){
    // this->curReport
}

void Complaint::activityFinished(){

}
