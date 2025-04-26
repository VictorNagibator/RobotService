#include "EngineHandler.h"

bool EngineHandler::handle(const IRobot& robot) 
{
    double temp = robot.getEngine()->getTemperature();
    std::cout << "[Диагностика] Температура двигателя: " << temp << "°C\n";
	double rpm = robot.getEngine()->getRPM();
	std::cout << "[Диагностика] Обороты двигателя: " << rpm << " об/мин\n";
    if (temp > robot.getEngine()->getTemperatureThreshold()) {
        std::cout << "[Диагностика] Ошибка: перегрев двигателя\n";
        return false;
    }
    if (rpm > robot.getEngine()->getMaxRPM()) {
        std::cout << "[Диагностика] Ошибка: превышены обороты двигателя\n";
        return false;
	}
    return DiagnosticHandler::handle(robot);
}