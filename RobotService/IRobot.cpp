#include "IRobot.h"
#include "CommunicationEncryptorDecorator.h"
#include "IdleState.h"
#include "DeliveringState.h"
#include "ChargingState.h"
#include "DiagnosticsState.h"
#include "ProxyIterator.h"
#include "MyList.h"

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

	observers = new MyList<IObserver*>(); //Создаем список наблюдателей
}

//Деструктор разрушает те объекты, которые были созданы в конструкторе
IRobot::~IRobot()
{
	delete state; //Удаляем текущее состояние
	delete observers; //Удаляем список наблюдателей
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
	message = "Робот доставляет груз"; //Уведомить наблюдателей о смене состояния
	notify();
}

void IRobot::startCharging() 
{ 
    changeState(new ChargingState(this)); 
	message = "Робот на зарядке"; //Уведомить наблюдателей о смене состояния
	notify();
}

void IRobot::runDiagnostics()
{ 
    changeState(new DiagnosticsState(this)); 
	message = "Робот проходит диагностику"; //Уведомить наблюдателей о смене состояния
	notify();
}

void IRobot::wait()
{
	changeState(new IdleState(this));
	message = "Робот ожидает"; //Уведомить наблюдателей о смене состояния
	notify();
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

void IRobot::attach(IObserver* observer)
{
	observers->push(observer);
}

void IRobot::detach(IObserver* observer)
{
	observers->remove(observer);
}

void IRobot::notify()
{
	auto it = ProxyIterator<IObserver*>(observers->begin());
	while (it.hasNext()) {
		IObserver* current = *(it.next());
		//Вызываем обновление состояния для каждого робота
		current->update(message);
	}
}

void IRobot::setMessage(const std::string& msg)
{
	message = "[Робот " + robotID;
	message += "]: " + msg;
}