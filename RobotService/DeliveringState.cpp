#include "DeliveringState.h"
#include "IRobot.h"

void DeliveringState::enter()
{
	robot->getCommunication()->establishConnection();
	std::cout << "[Робот №" << robot->getRobotID() << "] Вошел в состояние доставки" << std::endl;
}

void DeliveringState::execute()
{
	robot->moveTo(destination);
	std::string message = "[Робот №" + robot->getRobotID();
	message += "] Доставляет груз";
	robot->getCommunication()->sendData(message);
}

void DeliveringState::exit()
{
	robot->getEngine()->stop();
	std::string message = "[Робот №" + robot->getRobotID();
	message += "] Доставил груз";
	robot->getCommunication()->sendData(message);
	robot->getCommunication()->disconnect();
	std::cout << "[Робот №" << robot->getRobotID() << "] Выходит из состояния доставки" << std::endl;
}

std::string DeliveringState::name() const
{
	return "Доставка";
}

void DeliveringState::DeliveringState::setDestination(const std::string& dest)
{
	destination = dest;
}