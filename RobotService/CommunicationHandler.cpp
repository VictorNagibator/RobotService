#include "CommunicationHandler.h"

bool CommunicationHandler::handle(const IRobot& robot) 
{
    int strength = robot.getCommunication()->getSignalStrength();
    std::cout << "[Диагностика] Сила сигнала средств связи: " << strength << "\n";
    if (strength < minSignal) {
        std::cout << "[Диагностика] Ошибка связи\n";
        return false;
    }
    return DiagnosticHandler::handle(robot);
}