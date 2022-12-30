#ifndef __EVALUATE__
#define __EVALUATE__

#include "Activity.h"

class Evaluate : public Activity
{
protected:
    std::string EvaluateContent;
public:
    Evaluate(std::string);
    ~Evaluate();

    std::string getEvaluateContent();
    void setEvaluateContent(std::string);


    virtual void activityStart();
    virtual void activityExecute();
    virtual void activityFinished();
};



#endif //  __EVALUATE__