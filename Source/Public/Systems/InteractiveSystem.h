#ifndef __INTERACTIVESYSTEM__
#define __INTERACTIVESYSTEM__

#include <Public.h>
#include <map>

class InteractiveSystem
{
protected:
    InteractiveSystem();
    InteractiveSystem(const InteractiveSystem&);

    static InteractiveSystem* Instance;
    

public:
    static InteractiveSystem* getInstance();

    std::map<std::string, std::string> MockSituationExplain;
    
    std::string MockCommunicationRecord;

    std::time_t MockMaintainStartTime;

    std::string MockMaintainDescription;

    EMaintainFlag MaintainEndFlag;

    EFaultType MockFaultType;

    std::time_t MockMaintainEndTime;

    std::string MockDispatcherID;

    ~InteractiveSystem();

    std::string getMockSituationExplain(std::string);
    
    std::string getMockCommunicationRecord();

    std::time_t getMockMaintainStartTime();

    std::string getMockMaintainDescription();

    void getMockMaintainEndEvent(std::time_t &, EMaintainFlag&);

    EFaultType getMockFaultType();

    std::string getMockDispatcherID();
};

#endif // __INTERACTIVESYSTEM__