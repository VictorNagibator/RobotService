#pragma once
#include "IController.h"
#include <vector>

//Центральный контроллер, распределяющий задания и мониторящий роботов
class CentralController : public IController {
private:
    std::vector<IRobot*> robots;
public:
    CentralController(const std::string& name) : IController(name) {}

    void addRobot(IRobot* robot) override;
    void dispatchDelivery(IRobot* robot, const std::string& destination) override;
    void monitorRobots() override;
};