#include "DiagnosticsState.h"
#include "IRobot.h"
#include "PowerSourceHandler.h"
#include "EngineHandler.h"
#include "CommunicationHandler.h"
#include "NavigationHandler.h"

void DiagnosticsState::enter()
{
	std::cout << "[����� �" << robot->getRobotID() << "] ����� � ��������� �����������" << std::endl;
}

void DiagnosticsState::execute()
{
    //���������� ������� ������������:
    DiagnosticHandler* firsthandler = new PowerSourceHandler();
	DiagnosticHandler* secondhandler = new EngineHandler();
	DiagnosticHandler* thirdhandler = new CommunicationHandler();
	DiagnosticHandler* fourthhandler = new NavigationHandler();

    firsthandler->setNext(secondhandler);
    secondhandler->setNext(thirdhandler);
    thirdhandler->setNext(fourthhandler);

    std::cout << "[����� �" << robot->getRobotID() << "] ������ �����������...\n";
    bool allOk = firsthandler->handle(*robot);
    if (allOk) {
        std::cout << "[����� �" << robot->getRobotID() << "] ����������� �������� �������\n";
    }
    else {
        std::cout << "[����� �" << robot->getRobotID() << "] ����������� ������� ��������\n";
    }

    delete firsthandler;
    delete secondhandler;
    delete thirdhandler;
    delete fourthhandler;
}

void DiagnosticsState::exit()
{
	std::cout << "[����� �" << robot->getRobotID() << "] ������� �� ��������� �����������" << std::endl;
}

std::string DiagnosticsState::name() const
{
	return "�����������";
}