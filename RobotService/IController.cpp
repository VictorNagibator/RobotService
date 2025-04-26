#include "IController.h"

std::string IController::getNameFromSnapshot(ControllerSnapshot* snap) const 
{
	return snap->name;
}

IAggregate<IRobot*>* IController::getRobotsFromSnapshot(ControllerSnapshot* snap) const
{
	return snap->robots;
}

ControllerSnapshot* IController::makeSnapshot(std::string name, IAggregate<IRobot*>* robots) const
{
	return new ControllerSnapshot(name, robots);
}

void IController::update(const std::string& message)
{
	std::cout << "[Наблюдение] " << controllerName << " получил сообщение:  " << message << "\n";
}