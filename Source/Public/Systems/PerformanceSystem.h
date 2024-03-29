#ifndef __PERFORMANCESYSTEM__
#define __PERFORMANCESYSTEM__

#include <Public.h>
#include <map>

class PerformanceSystem
{
protected:
    PerformanceSystem(){};
    ~PerformanceSystem(){};

    static PerformanceSystem* Instance;
    // key：工人ID， 总工时
    std::map<std::string, std::time_t> LaborHourMap;


public:
    static PerformanceSystem* getInstance();

    static void DestoryInstance();


    time_t getWorkerLaborHour(std::string);

    void addWorkerLaborHour(std::string, const std::time_t&);
};



#endif // __PERFORMANCESYSTEM__