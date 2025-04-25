#include "IRobot.h"
#include "CommunicationEncryptorDecorator.h"
#include "IdleState.h"
#include "DeliveringState.h"
#include "ChargingState.h"
#include "DiagnosticsState.h"

IRobot::IRobot(int id, const std::string& model, IEngine* eng,
    INavigation* nav, ICommunication* comm, IPowerSource* power)
{
    robotID = id;
    modelName = model;
    engine = eng;
    navigation = nav;
    communication = comm;
    powerSource = power;

	state = new IdleState(this); //���������� ����� � ��������� ��������
}

void IRobot::changeState(IRobotState* s)
{
    state->exit();
    delete state;
    state = s;
    state->enter();
}

void IRobot::execute()
{
	try
	{
		//��������� �������� � ����������� �� ���������
		state->execute();
	}
	catch (const std::exception& e)
	{
		std::cout << "������: " << e.what() << "\n";
	}
}

//������ ��� ����� ���������
void IRobot::startDelivery(const std::string& destination) 
{ 
	auto deliveryState = new DeliveringState(this);
	deliveryState->setDestination(destination); //���������� ����� ����������
    changeState(deliveryState); 
}

void IRobot::startCharging() 
{ 
    changeState(new ChargingState(this)); 
}

void IRobot::runDiagnostics()
{ 
    changeState(new DiagnosticsState(this)); 
}

void IRobot::wait()
{
	changeState(new IdleState(this));
}

IEngine* IRobot::getEngine() const
{
	return engine;
}

INavigation* IRobot::getNavigation() const
{
	return navigation;
}

ICommunication* IRobot::getCommunication() const
{
	return communication;
}

IPowerSource* IRobot::getPowerSource() const
{
	return powerSource;
}

int IRobot::getRobotID() const
{
	return robotID;
}

std::string IRobot::getModelName() const
{
	return modelName;
}