#include "Systems/PerformanceSystem.h"

PerformanceSystem* PerformanceSystem::Instance = nullptr;

PerformanceSystem* PerformanceSystem::getInstance()
{
    if (Instance == nullptr)
    {
        Instance = new PerformanceSystem();
    }

    return Instance;
}

time_t PerformanceSystem::getWorkerLaborHour(std::string workerID)
{
    return LaborHourMap.find(workerID) == LaborHourMap.end()? 0:LaborHourMap[workerID];
}

void PerformanceSystem::addWorkerLaborHour(std::string workerID, const time_t& laborHour)
{
    if (LaborHourMap.find(workerID) == LaborHourMap.end())
    {
        LaborHourMap[workerID] = laborHour;
    }else
    {
        LaborHourMap[workerID] += laborHour;
    }
}