#include "IController.h"

std::string IController::getName(ControllerSnapshot* snap) const 
{
	return snap->name;
}

IAggregate<IRobot*>* IController::getRobots(ControllerSnapshot* snap) const
{
	return snap->robots;
}

ControllerSnapshot* IController::makeSnapshot(std::string name, IAggregate<IRobot*>* robots) const
{
	return new ControllerSnapshot(name, robots);
}