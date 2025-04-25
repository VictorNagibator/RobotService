#include "DiagnosticsState.h"
#include "IRobot.h"

void DiagnosticsState::enter()
{
	std::cout << "[����� �" << robot->getRobotID() << "] ����� � ��������� �����������" << std::endl;
}

void DiagnosticsState::execute()
{
	std::cout << "�� ������ ��������";
}

void DiagnosticsState::exit()
{
	std::cout << "[����� �" << robot->getRobotID() << "] ������� �� ��������� �����������" << std::endl;
}

std::string DiagnosticsState::name() const
{
	return "�����������";
}