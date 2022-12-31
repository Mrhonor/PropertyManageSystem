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

    ~InteractiveSystem();

    std::string getMockSituationExplain(std::string);
    
};

#endif // __INTERACTIVESYSTEM__