#ifndef __DISPATCHSYSTEM__
#define __DISPATCHSYSTEM__

#include <Public.h>
#include <Systems/Worker.h>
#include <Systems/Report.h>

class Maintain;

class DispatchSystem
{
protected:
    std::vector<Worker> WorkerList;
    
    
public:
    DispatchSystem();
    ~DispatchSystem();

    // 调度函数
    Activity* Dispatch(std::string dispatcherID, Report& dispatchReport);

    // 添加worker
    int addWorker(Worker &worker);
};


#endif // __DISPATCHSYSTEM__
