#include "CentralController.h"

void CentralController::addRobot(IRobot* robot)
{
    robots.push_back(robot);
    std::cout << controllerName << ": робот добавлен.\n";
}

void CentralController::dispatchDelivery(IRobot* robot, const std::string& destination)
{
    //Можно работать только с роботами, которые есть в системе
    if (std::find(robots.begin(), robots.end(), robot) == robots.end()) 
		throw std::invalid_argument("Робот не зарегистрирован в системе!");

    std::cout << controllerName << ": назначение доставки до " << destination << "\n";
    robot->startDelivery(destination);

    //В дальнейшем можно будет добавить логику ожидания, контроля процесса доставки и т.д.

    robot->stopDelivery();
}

void CentralController::monitorRobots()
{
    std::cout << controllerName << ": проверяем состояние роботов...\n";
    for (auto r : robots) {
        r->checkStatus();
    }
}

void CentralController::removeRobot(IRobot* robot)
{
	auto it = std::find(robots.begin(), robots.end(), robot);
	if (it != robots.end()) {
		robots.erase(it);
		std::cout << controllerName << ": робот удален.\n";
	}
	else {
		std::cout << controllerName << ": робот не найден.\n";
	}
}