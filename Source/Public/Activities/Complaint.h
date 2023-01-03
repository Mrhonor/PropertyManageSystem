#ifndef __COMPLAINT__
#define __COMPLAINT__

#include "Activity.h"
#include <map>
#include <set>

class Report;

class Complaint : public Activity
{
protected:
    std::string ComplaintContent;

    // 情况说明。key:工人ID
    std::map<std::string, std::string> SituationExplain;

    // 与客户沟通结果
    std::string CommunicationRecord;

    Report* CorReport;

    void getRelatePersonID(std::set<std::string>&);

public:
    Complaint(std::string, Report* corReport);
    ~Complaint();

    virtual void activityStart();
    virtual void activityExecute();
    virtual void activityFinished();

    std::string getComplaintContent();
    void setComplaintContent(std::string);

    std::string getCommunicationRecord();
    void setCommunicationRecord(std::string);

    const std::map<std::string, std::string>& getSituationExplain();
    void insertSituationExplain(std::string workerID, std::string explain);
    void eraseSituationExplain(std::string workerID);
};



#endif //  __COMPLAINT__