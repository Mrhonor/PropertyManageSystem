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
    DispatchSystem(){};

    static DispatchSystem* Instance;
    
public:

    static DispatchSystem* getInstance();

    ~DispatchSystem(){};

    // 调度函数
    Activity* Dispatch(std::string dispatcherID, Report& dispatchReport);

    // 添加worker
    int addWorker(Worker &worker);

    // 更新worker状态
    void updateWorkerState(std::string workerID, EWorkerState state);

    //
    Worker* getWorkerByID(std::string workerID);
};


#endif // __DISPATCHSYSTEM__
