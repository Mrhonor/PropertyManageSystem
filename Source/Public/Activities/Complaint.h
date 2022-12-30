#ifndef __COMPLAINT__
#define __COMPLAINT__

#include "Activity.h"
#include <map>

class Complaint : public Activity
{
protected:
    std::string ComplaintContend;

    // 情况说明。key:工人ID
    std::map<std::string, std::string> SituationExplain;

    // 与客户沟通结果
    std::string CommunicationRecord;

public:
    Complaint(std::string);
    ~Complaint();

    virtual void activityStart();
    virtual void activityExecute();
    virtual void activityFinished();

    std::string getComplaintContend();
    void setComplaintContend(std::string);

    std::string getCommunicationRecord();
    void setCommunicationRecord(std::string);

    const std::map<std::string, std::string>& getSituationExplain();
    void insertSituationExplain(std::string workerID, std::string explain);
};



#endif //  __COMPLAINT__