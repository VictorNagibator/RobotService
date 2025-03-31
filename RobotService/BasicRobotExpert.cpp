#include "BasicRobotExpert.h"
#include "MyList.h"
#include "ProxyIterator.h"

BasicRobotExpert::BasicRobotExpert(double maxSafeTemperatureForEngine, double minBatteryLevel) 
{
    this->maxSafeTemperatureForEngine = maxSafeTemperatureForEngine;
    this->minBatteryLevel = minBatteryLevel;
}

bool BasicRobotExpert::isRobotSuitable(IRobot* robot) const
{
    if (robot->getPowerSource().getCharge() < minBatteryLevel 
        || robot->getEngine().getTemperature() < maxSafeTemperatureForEngine)
        return false;
    return true;
}

MyList<IRobot*> BasicRobotExpert::filterSuitableRobots(const IAggregate<IRobot*>& allRobots) const
{
    MyList<IRobot*> suitable;
    ProxyIterator<IRobot*> it = allRobots.begin();
    while (it.hasNext()) {
        IRobot* robot = *(it.next());
        if (isRobotSuitable(robot)) {
            suitable.push(robot); //Добавляем только подходящих роботов
        }
    }
    return suitable;
}