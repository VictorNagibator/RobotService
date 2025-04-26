#include "EngineHandler.h"

bool EngineHandler::handle(const IRobot& robot) 
{
    double temp = robot.getEngine()->getTemperature();
    std::cout << "[�����������] ����������� ���������: " << temp << "�C\n";
	double rpm = robot.getEngine()->getRPM();
	std::cout << "[�����������] ������� ���������: " << rpm << " ��/���\n";
    if (temp > robot.getEngine()->getTemperatureThreshold()) {
        std::cout << "[�����������] ������: �������� ���������\n";
        return false;
    }
    if (rpm > robot.getEngine()->getMaxRPM()) {
        std::cout << "[�����������] ������: ��������� ������� ���������\n";
        return false;
	}
    return DiagnosticHandler::handle(robot);
}