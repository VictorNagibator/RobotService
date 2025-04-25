#include "DeliveringState.h"
#include "IRobot.h"

void DeliveringState::enter()
{
	robot->getCommunication()->establishConnection();
	std::cout << "[����� �" << robot->getRobotID() << "] ����� � ��������� ��������" << std::endl;
}

void DeliveringState::execute()
{
	robot->moveTo(destination);
	std::string message = "[����� �" + robot->getRobotID();
	message += "] ���������� ����";
	robot->getCommunication()->sendData(message);
}

void DeliveringState::exit()
{
	robot->getEngine()->stop();
	std::string message = "[����� �" + robot->getRobotID();
	message += "] �������� ����";
	robot->getCommunication()->sendData(message);
	robot->getCommunication()->disconnect();
	std::cout << "[����� �" << robot->getRobotID() << "] ������� �� ��������� ��������" << std::endl;
}

std::string DeliveringState::name() const
{
	return "��������";
}

void DeliveringState::DeliveringState::setDestination(const std::string& dest)
{
	destination = dest;
}