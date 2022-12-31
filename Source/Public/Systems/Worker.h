#ifndef __WORKER__
#define __WORKER__

#include <set>
#include <Public.h>
class Maintain;

class Worker
{
protected:
    std::string ID;
    std::set<EFaultType> HandleableFaultType;
    EWorkerState CurState;
    Maintain* CurMaintain;

public:
    Worker(std::string workerID,
            std::set<EFaultType> handleSet);
    ~Worker();

    EWorkerState getCurState();

    void setCurState(EWorkerState);

    bool checkHandleable(EFaultType faultType);

    Maintain* getCurMaintain();

    void setCurMaintain(Maintain *);
};


#endif // __WORKER__