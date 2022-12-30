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

// 评价内容
typedef struct 
{
    int ResponseTime;
    int ServiceAttitude;
    int Satisfaction;
}SEvaluteContent;


#endif // __ACTIVTITY__