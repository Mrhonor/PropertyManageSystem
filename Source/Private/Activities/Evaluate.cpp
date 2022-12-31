#include "Activities/Evaluate.h"

using namespace std;

Evaluate::Evaluate(SEvaluteContent evaluateContent):Activity(), EvaluateContent(evaluateContent){
    this->ActivityType = EActivityType::EvaluateType;
}

Evaluate::~Evaluate(){

}

SEvaluteContent Evaluate::getEvaluateContent(){
    return this->EvaluateContent;
}

void Evaluate::setEvaluateContent(SEvaluteContent newEval){
    this->EvaluateContent = newEval;
}

