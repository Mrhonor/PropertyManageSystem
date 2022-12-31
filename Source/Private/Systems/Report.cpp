#include "Systems/Report.h"
#include "Activities/Maintain.h"

Report::Report(std::string reportID)
{
    ID = reportID;
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

void Report::setReportSource(EReportSource reportSource)
{
    ReportSource = reportSource;
}

std::time_t Report::getReportTime()
{
    return ReportTime;
}

void Report::setReportTime(std::time_t reportTime)
{
    ReportTime = reportTime;
}

Activity* Report::getCurActiveActivity()
{
    Activity* curActivity = nullptr;
    for(auto activity:ActivityList)
    {
        EActivityType actType = activity.getActivityType();

        if (actType == MaintainType)
        {
            curActivity = &activity;
        }
    }

    return curActivity;
}

const std::vector<Activity>& Report::getActivityList()
{
    return ActivityList;
}

std::vector<TMaintainRecord> Report::getMaintainRecords()
{
    std::vector<TMaintainRecord> maintainReords;
    for (auto activity:ActivityList)
    {
        if (activity.getActivityType() == MaintainType)
        {
            TMaintainRecord mainrainRecord;
            mainrainRecord = activity.getMaintainRecord();
            maintainReords.push_back(mainrainRecord);
        }
    }

    return maintainReords;
}

time_t Report::countAllWorkTime()
{
    time_t allWorkTime = 0;
    for (auto activity:ActivityList)
    {
        if (activity.getActivityType() == MaintainType)
        {
            allWorkTime += activity.getLaborHour();
        }
    }

    return allWorkTime;
}

void Report::insertActivity(Activity &activity)
{
    ActivityList.push_back(activity);
}