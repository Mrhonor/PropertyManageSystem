#ifndef __REPORT__
#define __REPORT__

#include <Public.h>
#include <Activities/Activity.h>

class Maintain;

class Report
{
protected:
    // 活动列表：存储当前报修下的所有类型的活动
    std::vector<Activity> ActivityList;

    // 报修ID
    std::string ID;

    // 业主ID
    std::string OwnerID;

    // 故障类型
    EFaultType FaultType;

    // 报修来源
    EReportSource ReportSource;

    // 报修时间
    std::time_t ReportTime;

public:
    Report();
    ~Report();

    std::string getID();
    std::string getOwnerID();
    EFaultType getFaultType();
    void setFaultType(EFaultType);
    EReportSource getReportSource();
    std::time_t getReportTime();
    Activity* getCurActiveActivity();
    std::vector<Activity>::const_iterator getActivityListConstIterator();

    // 获取维修记录
    void getMaintainList(std::vector<Maintain>&);

    // 统计工时
    int countAllWorkTime();

    // 插入新的活动
    void insertActivity(Activity&);
};                


#endif // __REPORT__