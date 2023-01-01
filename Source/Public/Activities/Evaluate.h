#ifndef __EVALUATE__
#define __EVALUATE__

#include "Activities/Activity.h"

class Evaluate : public Activity
{
protected:
    TEvaluteContent EvaluateContent;
public:
    Evaluate(TEvaluteContent);
    ~Evaluate();

    TEvaluteContent getEvaluateContent();
    void setEvaluateContent(TEvaluteContent);

};



#endif //  __EVALUATE__