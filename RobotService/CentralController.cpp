#include "CentralController.h"

void CentralController::addRobot(IRobot* robot)
{
    robots.push_back(robot);
    std::cout << controllerName << ": робот добавлен.\n";
}

void CentralController::dispatchDelivery(IRobot* robot, const std::string& destination)
{
    std::cout << controllerName << ": назначение доставки до " << destination << "\n";
    robot->startDelivery(destination);

    //В дальнейшем можно будет добавить логику ожидания, контроля процесса доставки и т.д.

    robot->stopDelivery();
}

void CentralController::monitorRobots()
{
    std::cout << controllerName << ": проверяем состояние роботов...\n";
    for (auto r : robots) {
        r->updateStatus();
    }
}