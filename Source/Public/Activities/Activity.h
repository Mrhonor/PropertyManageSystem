#ifndef __ACTIVTITY__
#define __ACTIVTITY__

#include <Public.h>


class Activity
{
protected:
    std::string ID;

    virtual void activityStart()=0;

    virtual void activityExecute()=0;

    virtual void activityFinished()=0;

    EActivityType ActivityType;
public:
    virtual EActivityType getActivityType();

    Activity();

    ~Activity();

    void active();

    std::string getID();

    void setID(std::string);

};


#endif // __ACTIVTITY__