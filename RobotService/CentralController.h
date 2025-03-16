#pragma once
#include "IController.h"
#include "IAggregate.h"
#include <vector>

//Центральный контроллер, распределяющий задания и мониторящий роботов
class CentralController : public IController {
private:
	IAggregate<IRobot*>* robots; //Коллекция роботов
public:
    CentralController(const std::string& name, IAggregate<IRobot*>* collection) 
        : IController(name), robots(collection) {}

    void addRobot(IRobot* robot) override;
	void removeRobot(IRobot* robot) override;
    void dispatchDelivery(IRobot* robot, const std::string& destination) override;
    void monitorRobots() override;
};