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

using namespace std;
// 维修工人需要了解当前分配给他的各种任务已经完成情况，包括调度给他的报修和需要他处理的投诉。

void test_worker(){
    InteractiveSystem* interactiveSystemInstance = InteractiveSystem::getInstance();
    DispatchSystem* DispatchSystemInstance = DispatchSystem::getInstance();
    ReportSystem* ReportSystemInstance = ReportSystem::getInstance();

    string ownerID = "owner1";
    EFaultType faultType = EFaultType::FaultType2;
    EReportSource reportSource = EReportSource::Source2;
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
    Worker* worker1 = new Worker(workerID1, handleableSet1);

    set<EFaultType> handleableSet2;
    handleableSet2.insert(EFaultType::FaultType2);
    string workerID2 = "worker2";
    Worker* worker2 = new Worker(workerID2, handleableSet2);

    set<EFaultType> handleableSet3;
    handleableSet3.insert(EFaultType::FaultType1);
    string workerID3 = "worker3";
    Worker* worker3 = new Worker(workerID3, handleableSet3);

    DispatchSystemInstance->addWorker(worker1);
    DispatchSystemInstance->addWorker(worker2);
    DispatchSystemInstance->addWorker(worker3);

    time_t reportTime = mktime(&reportTimetm);
    Report* reportNormal = ReportSystemInstance->generateReport(ownerID, faultType, reportSource, reportTime);

    // 报修流程
    string dispatcherID = "dispatcher1";
    Maintain* normalMaintain = dynamic_cast<Maintain*>(DispatchSystemInstance->Dispatch(dispatcherID, *reportNormal));

    string curWorkerID = ((Maintain*)(reportNormal->getCurActiveActivity()))->getWorkerID();

    struct tm MaintainStartTime = reportTimetm;
    MaintainStartTime.tm_hour = 8;

    interactiveSystemInstance->MockMaintainStartTime = mktime(&MaintainStartTime);
    interactiveSystemInstance->MockMaintainDescription = "ok";

    struct tm MaintainEndTime = reportTimetm;
    MaintainEndTime.tm_hour = 18;
    interactiveSystemInstance->MockMaintainEndTime = mktime(&MaintainEndTime);

    interactiveSystemInstance->MaintainEndFlag = EMaintainFlag::Normal;


    assert(worker2->getCurState() == EWorkerState::Working);
    assert(worker2->getCurMaintain() == normalMaintain);


    normalMaintain->activityStart();
    assert(worker2->getActivityIDList().back() == normalMaintain->getID());
    normalMaintain->activityExecute();
    normalMaintain->activityFinished();
    assert(worker2->getCurState() == EWorkerState::Idle);
    assert(worker2->getCurMaintain() == nullptr);;

    // 投诉流程
    Complaint* complaintNormal = ReportSystemInstance->generateComplaint(reportNormal, "投诉内容");

    interactiveSystemInstance->MockSituationExplain.insert(pair<string, string>(workerID2, "worker2-情况说明"));
    interactiveSystemInstance->MockSituationExplain.insert(pair<string, string>(dispatcherID, "dispatcher1-情况说明"));
    interactiveSystemInstance->MockCommunicationRecord = "物业经理-客户沟通";

    complaintNormal->activityStart();    
    assert(worker2->getActivityIDList().back() == complaintNormal->getID());
    complaintNormal->activityExecute();
    complaintNormal->activityFinished();
    assert(worker2->getActivityIDList().size() == 0);

    InteractiveSystem::DestoryInstance();
    DispatchSystem::DestoryInstance();
    ReportSystem::DestoryInstance();
}