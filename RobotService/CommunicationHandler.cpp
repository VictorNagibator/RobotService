#include "CommunicationHandler.h"

bool CommunicationHandler::handle(const IRobot& robot) 
{
    int strength = robot.getCommunication()->getSignalStrength();
    std::cout << "[�����������] ���� ������� ������� �����: " << strength << "\n";
    if (strength < minSignal) {
        std::cout << "[�����������] ������ �����\n";
        return false;
    }
    return DiagnosticHandler::handle(robot);
}