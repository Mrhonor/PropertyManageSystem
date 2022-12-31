#include "Activities/Evaluate.h"

using namespace std;

Evaluate::Evaluate(TEvaluteContent evaluateContent):Activity(), EvaluateContent(evaluateContent){
    this->ActivityType = EActivityType::EvaluateType;
}

Evaluate::~Evaluate(){

}

TEvaluteContent Evaluate::getEvaluateContent(){
    return this->EvaluateContent;
}

void Evaluate::setEvaluateContent(TEvaluteContent newEval){
    this->EvaluateContent = newEval;
}

