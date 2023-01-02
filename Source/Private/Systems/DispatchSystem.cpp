#include <iostream>
#include "Systems/DispatchSystem.h"
#include "Systems/Worker.h"
#include "Systems/Report.h"
#include "Activities/Activity.h"
#include "Activities/Maintain.h"

DispatchSystem* DispatchSystem::Instance = nullptr;

DispatchSystem* DispatchSystem::getInstance(){
    if(Instance == nullptr){
        Instance = new DispatchSystem();
    }
    return Instance;
}

//添加工人
int DispatchSystem::addWorker(Worker &worker)
{
    WorkerList.push_back(worker);
}

Activity* DispatchSystem::Dispatch(std::string dispatcherID, Report& dispatchReport)
{
    EFaultType faultType;
    std::string workerID;
    int selectedWorker = -1;
    for (int i = 0; i<WorkerList.size(); i++)
    {
        faultType = dispatchReport.getFaultType();
        if (WorkerList[i].checkHandleable(faultType))
        {
            selectedWorker = i;
            break;
        }
    }

    if (selectedWorker < 0)
    {
        //不应该走到这里！！
        std::cout<<"Dispatch Failed"<<std::endl;
    }

    WorkerList[selectedWorker].setCurState(Working);
    workerID = WorkerList[selectedWorker].getWorkerID();
    
    Maintain activity(dispatcherID, workerID, &dispatchReport);
    dispatchReport.insertActivity(activity);

    return &activity;
}

void DispatchSystem::updateWorkerState(std::string workerID, EWorkerState state)
{
    Worker* targetWorker = getWorkerByID(workerID);

    if (targetWorker == nullptr)
    {
        //不应该走到这里！！
        std::cout<<"updateWorkerState Failed"<<std::endl;
        return ;
    }

    targetWorker->setCurState(state);
}

Worker* DispatchSystem::getWorkerByID(std::string workerID)
{
    for (int i=0; i<WorkerList.size(); i++)
    {
        if (WorkerList[i].getWorkerID() == workerID)
        {
            return &WorkerList[i];
        }
    }

    return nullptr;
}


