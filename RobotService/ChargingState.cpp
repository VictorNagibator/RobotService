#include "ChargingState.h"
#include "IRobot.h"

void ChargingState::enter() 
{
	std::cout << "[����� �" << robot->getRobotID() << "] ����� � ��������� �������" << std::endl;
}

void ChargingState::execute() 
{ 
	std::cout << "[����� �" << robot->getRobotID() << "] ����������" << std::endl;
	robot->getPowerSource()->recharge();
}

void ChargingState::exit() 
{ 
	std::cout << "[����� �" << robot->getRobotID() << "] ������� �� ��������� �������" << std::endl;
}

std::string ChargingState::name() const 
{ 
	return "�������";
}