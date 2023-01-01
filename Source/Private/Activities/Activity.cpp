#include "Activities/Activity.h"

using namespace std;


Activity::Activity(){

}

Activity::~Activity(){

}

void Activity::active(){
    activityStart();
    activityExecute();
    activityFinished();
}

EActivityType Activity::getActivityType(){
    return this->ActivityType;
}

std::string Activity::getID(){
    return this->ID;
}

void Activity::setID(string newID){
    this->ID = newID;
}

void Activity::activityStart(){

}

void Activity::activityExecute(){
    
}

void Activity::activityFinished(){
    
}

