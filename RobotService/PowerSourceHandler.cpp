#include "PowerSourceHandler.h"

bool PowerSourceHandler::handle(const IRobot& robot) 
{
    double lvl = robot.getPowerSource()->getCharge();
    std::cout << "[�����������] ������� ������: " << lvl << "%\n";
    if (lvl < minCharge) {
        std::cout << "[�����������] ������: ������ �����\n";
        return false;
    }
    return DiagnosticHandler::handle(robot);
}