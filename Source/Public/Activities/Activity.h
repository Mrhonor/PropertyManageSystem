#ifndef __ACTIVTITY__
#define __ACTIVTITY__

#include <Public.h>


class Activity
{
protected:
    virtual void activityStart()=0;

    virtual void activityExecute()=0;

    virtual void activityFinished()=0;

public:
    Activity();

    ~Activity();

    void active();
};


#endif // __ACTIVTITY__