#include "RobotGroup.h"
#include "MyList.h"
#include "ProxyIterator.h"

void RobotGroup::addRobot(IRobot* robot)
{
	robots->push(robot);
}

void RobotGroup::removeRobot(IRobot* robot)
{
	robots->remove(robot);
}

void RobotGroup::startDelivery(const std::string& destination)
{
	//Делегируем вызов всем роботам в группе
	auto it = ProxyIterator<IRobot*>(robots->begin());
	while (it.hasNext()) {
		(*it.next())->startDelivery(destination);
	}
}

void RobotGroup::stopDelivery()
{
	//Аналогично
	auto it = ProxyIterator<IRobot*>(robots->begin());
	while (it.hasNext()) {
		(*it.next())->stopDelivery();
	}
}

void RobotGroup::checkStatus()
{
	//Аналогично
	auto it = ProxyIterator<IRobot*>(robots->begin());
	while (it.hasNext()) {
		(*it.next())->checkStatus();
	}
}