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