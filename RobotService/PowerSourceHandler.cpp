#include "PowerSourceHandler.h"

bool PowerSourceHandler::handle(const IRobot& robot) 
{
    double lvl = robot.getPowerSource()->getCharge();
    std::cout << "[Диагностика] Уровень заряда: " << lvl << "%\n";
    if (lvl < minCharge) {
        std::cout << "[Диагностика] Ошибка: низкий заряд\n";
        return false;
    }
    return DiagnosticHandler::handle(robot);
}