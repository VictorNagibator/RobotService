#include "IdleState.h"
#include "IRobot.h"

void IdleState::enter() 
{
	std::cout << "[����� �" << robot->getRobotID() << "] ����� � ��������� ��������" << std::endl;
}

void IdleState::execute() 
{ 
	std::cout << "[����� �" << robot->getRobotID() << "] ������� �������" << std::endl;
}

void IdleState::exit() 
{ 
	std::cout << "[����� �" << robot->getRobotID() << "] ������� �� ��������� ��������" << std::endl;
}

std::string IdleState::name() const 
{
	return "��������";
}