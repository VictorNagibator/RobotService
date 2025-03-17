#pragma once
#include "IRobot.h"

//Интерфейс центрального контроллера
class IController {
protected:
    std::string controllerName;
public:
	IController(const std::string& name) : controllerName(name) {};

    virtual void addRobot(IRobot* robot) = 0;
	virtual void removeRobot(IRobot* robot) = 0;
    virtual void dispatchDelivery(IRobot* robot, const std::string& destination) = 0;
    virtual void monitorRobots() = 0;
};