#ifndef __EVALUATE__
#define __EVALUATE__

#include "Activity.h"

class Evaluate : public Activity
{
protected:
    TEvaluteContent EvaluateContent;
public:
    Evaluate(TEvaluteContent);
    ~Evaluate();

    TEvaluteContent getEvaluateContent();
    void setEvaluateContent(TEvaluteContent);

    virtual void activityStart();
    virtual void activityExecute();
    virtual void activityFinished();
};



#endif //  __EVALUATE__