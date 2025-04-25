#include "IdleState.h"
#include "IRobot.h"

void IdleState::enter() 
{
	std::cout << "[Робот №" << robot->getRobotID() << "] Вошел в состояние ожидания" << std::endl;
}

void IdleState::execute() 
{ 
	std::cout << "[Робот №" << robot->getRobotID() << "] Ожидает команды" << std::endl;
}

void IdleState::exit() 
{ 
	std::cout << "[Робот №" << robot->getRobotID() << "] Выходит из состояния ожидания" << std::endl;
}

std::string IdleState::name() const 
{
	return "Ожидание";
}