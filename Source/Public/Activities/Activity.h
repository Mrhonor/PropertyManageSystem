#ifndef __ACTIVTITY__
#define __ACTIVTITY__

#include <Public.h>


class Activity
{
protected:
    std::string ID;

    virtual void activityStart();

    virtual void activityExecute();

    virtual void activityFinished();

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