#include "BasicRobotExpert.h"
#include "MyList.h"
#include "ProxyIterator.h"

BasicRobotExpert::BasicRobotExpert(IController* ctrl, double maxSafeTemperatureForEngine, double minBatteryLevel) 
	: IRobotExpert(ctrl)
{
    this->maxSafeTemperatureForEngine = maxSafeTemperatureForEngine;
    this->minBatteryLevel = minBatteryLevel;
}

int BasicRobotExpert::countSuitableRobots() const
{
	int count = 0;
	ProxyIterator<IRobot*> it (controller->getRobots().begin());
	while (it.hasNext()) {
		IRobot* robot = *(it.next());

		double robotCharge = robot->getPowerSource()->getCharge();
		double robotTemperature = robot->getEngine()->getTemperature();

		//Считаем для условий по доставке
		if (robotCharge >= minBatteryLevelForDelivery && robotTemperature <= maxTemperatureForDelivery) {
			count++;
		}
	}
	return count;
}

int BasicRobotExpert::countRobotsInNeedOfService() const
{
	int count = 0;
	ProxyIterator<IRobot*> it(controller->getRobots().begin());
	while (it.hasNext()) {
		IRobot* robot = *(it.next());

		double robotCharge = robot->getPowerSource()->getCharge();
		double robotTemperature = robot->getEngine()->getTemperature();

		//Считаем для критических условий
		if (robotCharge < minBatteryLevel || robotTemperature > maxSafeTemperatureForEngine) {
			count++;
		}
	}
	return count;
}