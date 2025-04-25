#include "ChargingState.h"
#include "IRobot.h"

void ChargingState::enter() 
{
	std::cout << "[Робот №" << robot->getRobotID() << "] Вошел в состояние зарядки" << std::endl;
}

void ChargingState::execute() 
{ 
	std::cout << "[Робот №" << robot->getRobotID() << "] Заряжается" << std::endl;
	robot->getPowerSource()->recharge();
}

void ChargingState::exit() 
{ 
	std::cout << "[Робот №" << robot->getRobotID() << "] Выходит из состояния зарядки" << std::endl;
}

std::string ChargingState::name() const 
{ 
	return "Зарядка";
}