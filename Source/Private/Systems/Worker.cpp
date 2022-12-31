#include "Systems/Worker.h"

Worker::Worker(std::string workerID, std::set<EFaultType> handleSet)
{
    ID = workerID;
    HandleableFaultType = handleSet;
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