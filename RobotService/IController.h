#pragma once
#include "IRobot.h"
#include "IAggregate.h"
#include "IRobotExpert.h"

//Интерфейс центрального контроллера
class IController {
protected:
    std::string controllerName;
	IRobotExpert* expert;
public:
	IController(const std::string& name, IRobotExpert* exp) : controllerName(name), expert(exp) {};

    virtual void addRobot(IRobot* robot) = 0;
	virtual void removeRobot(IRobot* robot) = 0;
    virtual void dispatchDelivery(IRobot* robot, const std::string& destination) = 0;
    virtual void monitorRobots() const = 0;

    virtual const IAggregate<IRobot*>& getRobots() const = 0;
    virtual const IRobotExpert& getRobotExpert() const;
};