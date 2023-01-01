#ifndef __REPORTSYSTEM__
#define __REPORTSYSTEM__

#include <Public.h>
#include <Systems/Report.h>

class Evaluate;
class Complaint;

// class ReportSystemSingleton

class ReportSystem
{
protected:
    ReportSystem(){};

    static ReportSystem* Instance;
    // 报修列表：存储所有的报修
    std::vector<Report> ReportList;

public:
    static ReportSystem* getInstance();

    ~ReportSystem();

    // 生成报修
    Report* generateReport(std::string ownerID, EFaultType faultType, EReportSource reportSource, std::time_t reportTime);

    // 生成评价
    Evaluate* generateEvaluate(Report* corReport, TEvaluteContent evaluateContent);

    // 生成投诉
    Complaint* generateComplaint(Report* corReport, std::string complaintContend);
};



#endif //__REPORTSYSTEM__