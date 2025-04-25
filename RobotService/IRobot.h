#pragma once
#include "IEngine.h"
#include "IPowerSource.h"
#include "ICommunication.h"
#include "INavigation.h"
#include "Prototype.h"

class IRobotState; //��������� �����, ��� ��� ����� ���������� ����������� include

//��������� ������
class IRobot : public Prototype {
protected:
    int robotID; //���������� ����� ������
    std::string modelName; //�������� ������
    IEngine* engine;
    INavigation* navigation;
    ICommunication* communication;
    IPowerSource* powerSource;

	IRobotState* state; //��������� ������ (��������, "����������", "�������", "� ����" � �.�.)

	virtual void changeState(IRobotState* s); //������� ��������� ������
public:
    IRobot(int id, const std::string& model, IEngine* engine,
        INavigation* nav, ICommunication* comm, IPowerSource* power);

    //��������� ��������
    virtual void execute();

    //������ ��� ����� ���������
    virtual void startDelivery(const std::string& destination);
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
};