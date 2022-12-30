#ifndef __MAINTAIN__
#define __MAINTAIN__

#include "Activity.h"

class Report;

class Maintain : public Activity
{
protected:
    std::string DispatcherID;
    std::string WorkerID;
    time_t MaintainStartTime;
    time_t MaintainEndTime;
    std::string MaintainDescription;
    Report* CorReport;

public:
    Maintain(std::string dispatcherID, std::string workerID, Report* corReport);
    ~Maintain();

    virtual void activityStart();
    virtual void activityExecute();
    virtual void activityFinished();

    std::string getDispatcherID();
    void setDispatcherID(std::string);

    std::string getWorkerID();
    void setWorkerID(std::string);

    std::string getMaintainDescription();
    void setMaintainDescription(std::string);

    time_t getMaintainStartTime();
    void setMaintainStartTime(time_t);

    time_t getMaintainEndTime();
    void setMaintainEndTime(time_t);

    Report* getCorReport();
    void setCorReport(Report*);

};



#endif //  __MAINTAIN__