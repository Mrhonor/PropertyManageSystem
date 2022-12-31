#include "ReportSystem.h"

Report::Report(std::string reportID)
{
    ID = reportID;
}

Report* ReportSystem::generateReport(std::string ownerID,
                                    EFaultType FaultType,
                                    EReportSource reportSource,
                                    std::time_t reportTime)
{
    //生成reportID
    std::string reportID;
    reportID = ownerID + std::to_string(FaultType) + std::to_string(reportSource) + std::to_string(reportTime);
    
    //新建report
    Report report(reportID);
    report.setOwnerID(ownerID);

}

std::string Report::getID()
{
    return ID;
}

void Report::setOwnerID(std::string ownerID)
{
    OwnerID = ownerID;
}

std::string Report::getOwnerID()
{
    return OwnerID;
}

EFaultType Report::getFaultType()
{
    return FaultType;
}

void Report::setFaultType(EFaultType faultType)
{
    FaultType = faultType;
}

EReportSource Report::getReportSource()
{
    return ReportSource;
}

std::time_t Report::getReportTime()
{
    return ReportTime;
}

Activity* Report::getCurActiveActivity()
{
    Activity* curActivity = nullptr;
    for(auto activity:ActivityList)
    {
        EActivityType actType = activity.getActivityType();

        if (actType == MainTain)
        {
            curActivity = &activity;
        }
    }

    return curActivity;
}

const std::vector<Activity>* Report::getActivityList()
{
    return &ActivityList;
}

void Report::getMaintainList(std::vector<Maintain>& MaintainList)
{
    for (auto activity:ActivityList)
    {
        if (activity.getActivityType() == Maintain)
        {
            (*MaintainList).push_back(activity);
        }
    }
}