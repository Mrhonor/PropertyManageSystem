#include "Activities/Maintain.h"
#include "Activities/Complaint.h"
#include "Activities/Evaluate.h"

#include "Systems/DispatchSystem.h"
#include "Systems/InteractiveSystem.h"
#include "Systems/ReportSystem.h"
#include "Systems/Report.h"
#include "Systems/Worker.h"

#include "Public.h"
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

void test_NormalWork(){
    printf("1\n");
    InteractiveSystem* interactiveSystemInstance = InteractiveSystem::getInstance();
    DispatchSystem* DispatchSystemInstance = DispatchSystem::getInstance();
    ReportSystem* ReportSystemInstance = ReportSystem::getInstance();

    string ownerID = "owner1";
    EFaultType faultType = EFaultType::FaultType1;
    EReportSource reportSource = EReportSource::Source1;
    struct tm reportTimetm;
    reportTimetm.tm_hour = 0;
    reportTimetm.tm_sec = 0;
    reportTimetm.tm_min = 0;
    reportTimetm.tm_mday = 1;
    reportTimetm.tm_mon = 0;
    reportTimetm.tm_year = 2022;
    reportTimetm.tm_wday = 6;
    reportTimetm.tm_yday = 0;
    reportTimetm.tm_isdst = 0;

    set<EFaultType> handleableSet1;
    handleableSet1.insert(EFaultType::FaultType1);
    string workerID1 = "worker1";
    Worker worker1(workerID1, handleableSet1);

    set<EFaultType> handleableSet2;
    handleableSet2.insert(EFaultType::FaultType2);
    string workerID2 = "worker2";
    Worker worker2(workerID2, handleableSet2);

    DispatchSystemInstance->addWorker(worker1);
    DispatchSystemInstance->addWorker(worker2);

    time_t reportTime = mktime(&reportTimetm);
    Report* reportNormal = ReportSystemInstance->generateReport(ownerID, faultType, reportSource, reportTime);


    // 报修流程
    string dispatcherID = "dispatcher1";
    Maintain* normalMaintain;

    Activity* activity = DispatchSystemInstance->Dispatch(dispatcherID, *reportNormal);

    normalMaintain = dynamic_cast<Maintain*>(activity);

    struct tm MaintainStartTime = reportTimetm;
    MaintainStartTime.tm_hour = 8;

    interactiveSystemInstance->MockMaintainStartTime = mktime(&MaintainStartTime);
    interactiveSystemInstance->MockMaintainDescription = "ok";
    printf("3\n");
    struct tm MaintainEndTime = reportTimetm;
    MaintainEndTime.tm_hour = 18;
    interactiveSystemInstance->MockMaintainEndTime = mktime(&MaintainEndTime);

    interactiveSystemInstance->MaintainEndFlag = EMaintainFlag::Normal;

    normalMaintain->active();
    printf("4\n");
    assert(normalMaintain->getWorkerID() == workerID1);
    assert(normalMaintain->getDispatcherID() == dispatcherID);
    assert(normalMaintain->getMaintainStartTime() == mktime(&MaintainStartTime));
    assert(normalMaintain->getMaintainEndTime() == mktime(&MaintainEndTime));
    assert(normalMaintain->getMaintainDescription() == interactiveSystemInstance->MockMaintainDescription);

    // 投诉流程
    Complaint* complaintNormal = ReportSystemInstance->generateComplaint(reportNormal, "投诉内容");

    interactiveSystemInstance->MockSituationExplain.insert(pair<string, string>(workerID1, "worker1-情况说明"));
    interactiveSystemInstance->MockSituationExplain.insert(pair<string, string>(dispatcherID, "dispatcher1-情况说明"));
    interactiveSystemInstance->MockCommunicationRecord = "物业经理-客户沟通";

    complaintNormal->active();
    auto SituationExplain = complaintNormal->getSituationExplain();
    assert(SituationExplain[workerID1] == "worker1-情况说明");
    assert(SituationExplain[dispatcherID] == "dispatcher1-情况说明");
    assert(complaintNormal->getCommunicationRecord() == "物业经理-客户沟通");

    TEvaluteContent evaluateContent;
    evaluateContent.ResponseTime = 5;
    evaluateContent.Satisfaction = 5;
    evaluateContent.ServiceAttitude = 5;

    Evaluate* evaluateNormal = ReportSystemInstance->generateEvaluate(reportNormal, evaluateContent);
    
    evaluateNormal->active();
    TEvaluteContent testEvaluateContent = evaluateNormal->getEvaluateContent();
    assert(!memcmp(&(testEvaluateContent), &evaluateContent, sizeof(TEvaluteContent)));
}