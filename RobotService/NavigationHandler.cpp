#include "NavigationHandler.h"

bool NavigationHandler::handle(const IRobot& robot) 
{
	bool ok = robot.getNavigation()->selfTest();
    std::cout << "[�����������] ������������ ���������: " << (ok ? "OK" : "������") << "\n";
    if (!ok) {
        std::cout << "[Diag] ������ ���������\n";
        return false;
    }
    return DiagnosticHandler::handle(robot);
}