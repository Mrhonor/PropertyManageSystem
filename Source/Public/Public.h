#ifndef __PUBLIC__
#define __PUBLIC__

#include <string>
#include <vector>
#include <ctime>

// 故障类型
typedef enum{
    FaultType1,
    FaultType2
}EFaultType;

// 报修来源
typedef enum{
    Source1,
    Source2
}EReportSource;

// 工人状态
typedef enum{
    Idle,
    Working
}EWorkerState;

typedef enum{
    MaintainType,
    ComplaintType,
    EvaluateType
}EActivityType;

// 评价内容
typedef struct 
{
    int ResponseTime;
    int ServiceAttitude;
    int Satisfaction;
}TEvaluteContent;

// 维修记录
typedef struct
{
    std::string DispatcherID;
    std::string WorkerID;
    time_t MaintainStartTime;
    time_t MaintainEndTime;
    std::string MaintainDescription;
}TMaintainRecord;


#endif // __ACTIVTITY__