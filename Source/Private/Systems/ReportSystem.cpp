#include "Systems/ReportSystem.h"
//#include "Activity.h"
#include "Activities/Maintain.h"
#include "Activities/Complaint.h"
#include "Activities/Evaluate.h"


ReportSystem* ReportSystem::Instance = nullptr;

ReportSystem* ReportSystem::getInstance(){
    if(Instance == nullptr){
        Instance = new ReportSystem();
    }
    return Instance;
}

ReportSystem::~ReportSystem(){
    for(auto i : ReportList){
        delete i;
    }
}

void ReportSystem::DestoryInstance(){
    if(Instance != nullptr){
        delete Instance;
        Instance = nullptr;
    }
}


Report* ReportSystem::generateReport(std::string ownerID,
                                    EFaultType faultType,
                                    EReportSource reportSource,
                                    std::time_t reportTime)
{
    //生成reportID
    std::string reportID;
    reportID = ownerID + std::to_string(faultType) + std::to_string(reportSource) + std::to_string(reportTime);
    
    //新建report
    Report* report = new Report(reportID);
    report->setOwnerID(ownerID);
    report->setFaultType(faultType);
    report->setReportSource(reportSource);
    report->setReportTime(reportTime);

    ReportList.push_back(report);

    return report;
}

Evaluate* ReportSystem::generateEvaluate(Report* corReport, TEvaluteContent evaluateContent)
{
    //生成评价
    Evaluate* evaluation = new Evaluate(evaluateContent);

    corReport->insertActivity(evaluation);

    return evaluation;
}

Complaint* ReportSystem::generateComplaint(Report* corReport, std::string complaintContend)
{
    //生成投诉
    Complaint* complaint = new Complaint(complaintContend, corReport);

    corReport->insertActivity(complaint);

    return complaint;
}
