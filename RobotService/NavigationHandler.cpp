#include "NavigationHandler.h"

bool NavigationHandler::handle(const IRobot& robot) 
{
	bool ok = robot.getNavigation()->selfTest();
    std::cout << "[Диагностика] Тестирование навигации: " << (ok ? "OK" : "ОШИБКА") << "\n";
    if (!ok) {
        std::cout << "[Diag] Ошибка навигации\n";
        return false;
    }
    return DiagnosticHandler::handle(robot);
}