#include "DiagnosticsState.h"
#include "IRobot.h"

void DiagnosticsState::enter()
{
	std::cout << "[Робот №" << robot->getRobotID() << "] Вошел в состояние диагностики" << std::endl;
}

void DiagnosticsState::execute()
{
	std::cout << "НЕ ЗАБУДЬ ДОБАВИТЬ";
}

void DiagnosticsState::exit()
{
	std::cout << "[Робот №" << robot->getRobotID() << "] Выходит из состояния диагностики" << std::endl;
}

std::string DiagnosticsState::name() const
{
	return "Диагностика";
}