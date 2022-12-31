#include <iostream>
#include "Systems/DispatchSystem.h"
#include "Systems/Worker.h"
#include "Systems/Report.h"
#include "Activities/Activity.h"
#include "Activities/Maintain.h"

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
    int workerIdx = -1;
    workerIdx = getWorkerIdxByID(workerID);

    if (workerIdx < 0)
    {
        //不应该走到这里！！
        std::cout<<"updateWorkerState Failed"<<std::endl;
        return ;
    }
}

int DispatchSystem::getWorkerIdxByID(std::string workerID)
{
    for (int i=0; i<WorkerList.size(); i++)
    {
        if (WorkerList[i].getWorkerID() == workerID)
        {
            return i;
        }
    }

    return -1;
}


