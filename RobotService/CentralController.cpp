#include "CentralController.h"
#include "ProxyIterator.h"

void CentralController::addRobot(IRobot* robot)
{
    robots->push(robot);
    std::cout << controllerName << ": робот добавлен.\n";
}

void CentralController::dispatchDelivery(IRobot* robot, const std::string& destination)
{
	//ћожно назначать доставку только зарегистрированным роботам
	bool isRobotInCollection = false;
    //ѕолучаем прокси итератор на коллекцию роботов
    auto it = ProxyIterator<IRobot*>(robots->begin());
    while (it.hasNext()) {
        if (*(it.next()) == robot) {
            isRobotInCollection = true;
            break;
        }
    }
    if (!isRobotInCollection) throw std::invalid_argument("–обот не зарегистрирован в системе!");

    std::cout << controllerName << ": назначение доставки до " << destination << "\n";
    robot->startDelivery(destination);

    //¬ дальнейшем можно будет добавить логику ожидани€, контрол€ процесса доставки и т.д.

    robot->stopDelivery();
}

void CentralController::monitorRobots() const
{
    std::cout << controllerName << ": провер€ем состо€ние роботов...\n";
    //ѕолучаем прокси итератор на коллекцию роботов дл€ автоматического удалени€
    auto it = ProxyIterator<IRobot*>(robots->begin());
    while (it.hasNext()) {
        IRobot* currentRobot = *(it.next());
        //¬ызываем обновление состо€ни€ дл€ каждого робота
        currentRobot->checkStatus();
    }
}

void CentralController::removeRobot(IRobot* robot)
{
	robots->remove(robot);
}

const IAggregate<IRobot*>& CentralController::getRobots() const
{
    return *robots;
}