#pragma once
#include "IEngine.h"
#include "IPowerSource.h"
#include "ICommunication.h"
#include "INavigation.h"
#include "Prototype.h"
#include "ISubject.h"
#include "IAggregate.h"
#include "IVendingMachine.h"

class IRobotState; //��������� �����, ��� ��� ����� ���������� ����������� include

//��������� ������
class IRobot : public Prototype, public ISubject {
protected:
    int robotID; //���������� ����� ������
    std::string modelName; //�������� ������
    IEngine* engine;
    INavigation* navigation;
    ICommunication* communication;
    IPowerSource* powerSource;

	IRobotState* state; //��������� ������ (��������, "����������", "�������", "� ����" � �.�.)

	IAggregate<IObserver*>* observers; //�����������, ������� ������ �� ���������� ������
	std::string message; //��������� ��� ������������

	virtual void changeState(IRobotState* s); //������� ��������� ������
public:
    IRobot(int id, const std::string& model, IEngine* engine,
        INavigation* nav, ICommunication* comm, IPowerSource* power);

    virtual ~IRobot();

    //��������� ��������
    virtual void execute();

    //������ ��� ����� ���������
    virtual void startDelivery(const std::string& destination, const std::string& machineLocation = nullptr,
        int itemID = -1,
        IVendingMachine* vendingMachine = nullptr); 
    virtual void startCharging();
    virtual void runDiagnostics();
    virtual void wait();

    virtual void checkStatus() = 0; //������ ��������� ������

	virtual void moveTo(const std::string& destination) = 0; //������������� � ����� ����������

    //����������� �������
	virtual int getRobotID() const;
	virtual std::string getModelName() const;
	virtual IEngine* getEngine() const;
	virtual INavigation* getNavigation() const;
	virtual ICommunication* getCommunication() const;
	virtual IPowerSource* getPowerSource() const;

    virtual IRobot* clone() const = 0;

	//������ ��� ������ � �������������
	virtual void attach(IObserver* observer) override; //�������� �����������
	virtual void detach(IObserver* observer) override; //������� �����������
	virtual void notify() override; //��������� ������������

	virtual void setMessage(const std::string& msg); //���������� ��������� ��� ������������
};