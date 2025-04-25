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

	state = new IdleState(this); //���������� ����� � ��������� ��������

	observers = new MyList<IObserver*>(); //������� ������ ������������
}

//���������� ��������� �� �������, ������� ���� ������� � ������������
IRobot::~IRobot()
{
	delete state; //������� ������� ���������
	delete observers; //������� ������ ������������
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
	message = "����� ���������� ����"; //��������� ������������ � ����� ���������
	notify();
}

void IRobot::startCharging() 
{ 
    changeState(new ChargingState(this)); 
	message = "����� �� �������"; //��������� ������������ � ����� ���������
	notify();
}

void IRobot::runDiagnostics()
{ 
    changeState(new DiagnosticsState(this)); 
	message = "����� �������� �����������"; //��������� ������������ � ����� ���������
	notify();
}

void IRobot::wait()
{
	changeState(new IdleState(this));
	message = "����� �������"; //��������� ������������ � ����� ���������
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
		//�������� ���������� ��������� ��� ������� ������
		current->update(message);
	}
}

void IRobot::setMessage(const std::string& msg)
{
	message = "[����� " + robotID;
	message += "]: " + msg;
}