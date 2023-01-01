#ifndef __REPORT__
#define __REPORT__

#include <Public.h>
#include <Activities/Activity.h>
#include <set>

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
    Report(std::string reportID);
    ~Report(){};

    std::string getID();

    std::string getOwnerID();
    void setOwnerID(std::string ownerid);
    
    EFaultType getFaultType();
    void setFaultType(EFaultType);

    EReportSource getReportSource();
    void setReportSource(EReportSource reportSource);

    std::time_t getReportTime();
    void setReportTime(std::time_t ReportTime);

    Activity* getCurActiveActivity();
    const std::vector<Activity>& getActivityList();

    // 获取维修记录
    //void getMaintainList(std::vector<Maintain>&);
    std::vector<TMaintainRecord> getMaintainRecords();

    // 统计工时
    time_t countAllWorkTime();

    // 插入新的活动
    void insertActivity(Activity &);

    void getRelatePersonID(std::set<std::string>&);
};                


#endif // __REPORT__