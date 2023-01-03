#include "Systems/Worker.h"
#include <algorithm>

Worker::Worker(std::string workerID, std::set<EFaultType> handleSet)
{
    ID = workerID;
    HandleableFaultType = handleSet;
    CurState = EWorkerState::Idle;
    CurMaintain = nullptr;
    ActivityIDList.clear();
}

Worker::~Worker(){
    
}

EWorkerState Worker::getCurState()
{
    return CurState;
}

void Worker::setCurState(EWorkerState state)
{
    CurState = state;
}

Maintain* Worker::getCurMaintain()
{
    return CurMaintain;
}

void Worker::setCurMaintain(Maintain *maintain)
{
    CurMaintain = maintain;
}

bool Worker::checkHandleable(EFaultType faultType)
{
    // 非空闲状态或无法处理此类故障
    if (CurState != Idle ||
        HandleableFaultType.find(faultType) == HandleableFaultType.end())
    {
        return false;
    }
    return true;
}

std::string Worker::getWorkerID()
{
    return ID;
}

void Worker::addActivityIDList(std::string newActivity){
    this->ActivityIDList.push_back(newActivity);
}

void Worker::removeActivityIDList(std::string targetID){
    auto iter = std::remove(this->ActivityIDList.begin(), this->ActivityIDList.end(), targetID);
    this->ActivityIDList.erase(iter, std::end(this->ActivityIDList));//Remove surplus elements

}

std::vector<std::string> Worker::getActivityIDList(){
    return ActivityIDList;
}
