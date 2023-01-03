#include "Activities/Activity.h"
#include <time.h>

using namespace std;

string getTime()  //2020-09-11 22:00:49 这个只能到秒
{
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
    return tmp;
}


Activity::Activity(){
    this->ID = getTime();
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

