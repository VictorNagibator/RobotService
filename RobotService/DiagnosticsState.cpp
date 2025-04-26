#include "DiagnosticsState.h"
#include "IRobot.h"
#include "PowerSourceHandler.h"
#include "EngineHandler.h"
#include "CommunicationHandler.h"
#include "NavigationHandler.h"

void DiagnosticsState::enter()
{
	std::cout << "[Робот №" << robot->getRobotID() << "] Вошел в состояние диагностики" << std::endl;
}

void DiagnosticsState::execute()
{
    //Построение цепочки обязанностей:
    DiagnosticHandler* firsthandler = new PowerSourceHandler();
	DiagnosticHandler* secondhandler = new EngineHandler();
	DiagnosticHandler* thirdhandler = new CommunicationHandler();
	DiagnosticHandler* fourthhandler = new NavigationHandler();

    firsthandler->setNext(secondhandler);
    secondhandler->setNext(thirdhandler);
    thirdhandler->setNext(fourthhandler);

    std::cout << "[Робот №" << robot->getRobotID() << "] Запуск диагностики...\n";
    bool allOk = firsthandler->handle(*robot);
    if (allOk) {
        std::cout << "[Робот №" << robot->getRobotID() << "] Диагностика пройдена успешно\n";
    }
    else {
        std::cout << "[Робот №" << robot->getRobotID() << "] Диагностика выявила проблемы\n";
    }

    delete firsthandler;
    delete secondhandler;
    delete thirdhandler;
    delete fourthhandler;
}

void DiagnosticsState::exit()
{
	std::cout << "[Робот №" << robot->getRobotID() << "] Выходит из состояния диагностики" << std::endl;
}

std::string DiagnosticsState::name() const
{
	return "Диагностика";
}