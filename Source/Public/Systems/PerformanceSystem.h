#ifndef __PERFORMANCESYSTEM__
#define __PERFORMANCESYSTEM__

#include <Public.h>
#include <map>

class Maintain;

class PerformanceSystem
{
protected:
    // key：工人ID， 总工时
    std::map<std::string, int> LaborHourMap;
public:
    PerformanceSystem();
    ~PerformanceSystem();

    void getWorkerLaborHour(std::string);

    void addWorkerLaborHour(std::string, const Maintain&);
};



#endif // __PERFORMANCESYSTEM__