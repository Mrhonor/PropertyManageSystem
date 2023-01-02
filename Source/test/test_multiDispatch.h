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

void test_multiDispatch(){
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
    Maintain* normalMaintain = dynamic_cast<Maintain*>(DispatchSystemInstance->Dispatch(dispatcherID, *reportNormal));


    struct tm MaintainStartTime = reportTimetm;
    MaintainStartTime.tm_hour = 8;

    interactiveSystemInstance->MockMaintainStartTime = mktime(&MaintainStartTime);
    interactiveSystemInstance->MockMaintainDescription = "ok";

    struct tm MaintainEndTime = reportTimetm;
    MaintainEndTime.tm_hour = 18;
    interactiveSystemInstance->MockMaintainEndTime = mktime(&MaintainEndTime);

    interactiveSystemInstance->MaintainEndFlag = EMaintainFlag::FaultTypeWrong;
    interactiveSystemInstance->MockFaultType = EFaultType::FaultType2;
    string dispatcherID2 = "dispatcher2";
    interactiveSystemInstance->MockDispatcherID = dispatcherID2;

    normalMaintain->active();

    assert(reportNormal->getFaultType() == EFaultType::FaultType2);
    assert(((Maintain*)(reportNormal->getCurActiveActivity()))->getWorkerID() == workerID2);


}