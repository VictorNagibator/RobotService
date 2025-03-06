#include "CentralController.h"

void CentralController::addRobot(IRobot* robot)
{
    robots.push_back(robot);
    std::cout << controllerName << ": робот добавлен.\n";
}

void CentralController::dispatchDelivery(IRobot* robot, const std::string& destination)
{
    //ћожно работать только с роботами, которые есть в системе
    if (std::find(robots.begin(), robots.end(), robot) == robots.end()) 
		throw std::invalid_argument("–обот не зарегистрирован в системе!");

    std::cout << controllerName << ": назначение доставки до " << destination << "\n";
    robot->startDelivery(destination);

    //¬ дальнейшем можно будет добавить логику ожидани€, контрол€ процесса доставки и т.д.

    robot->stopDelivery();
}

void CentralController::monitorRobots()
{
    std::cout << controllerName << ": провер€ем состо€ние роботов...\n";
    for (auto r : robots) {
        r->checkStatus();
    }
}