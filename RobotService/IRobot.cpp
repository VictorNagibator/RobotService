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

	state = new IdleState(this); //Изначально робот в состоянии ожидания
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
		//Выполнить действие в зависимости от состояния
		state->execute();
	}
	catch (const std::exception& e)
	{
		std::cout << "Ошибка: " << e.what() << "\n";
	}
}

//Методы для смены состояния
void IRobot::startDelivery(const std::string& destination) 
{ 
	auto deliveryState = new DeliveringState(this);
	deliveryState->setDestination(destination); //Установить точку назначения
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