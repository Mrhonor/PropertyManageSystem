#ifndef __WORKER__
#define __WORKER__

#include <Public.h>
class Maintain;

class Worker
{
protected:
    std::string ID;
    std::vector<EFaultType> HandleableFaultType;
    EWorkerState CurState;
    Maintain* CurMaintain;

public:
    Worker();
    ~Worker();

    EWorkerState getCurState();

    void setCurState(EWorkerState);

    bool checkHandleable();

    Maintain* getCurMaintain();

    void setCurMaintain(Maintain&);
};


#endif // __WORKER__