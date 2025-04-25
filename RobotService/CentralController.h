#pragma once
#include "IController.h"
#include "MyList.h"

//����������� ����������, �������������� ������� � ����������� �������
class CentralController : public IController {
private:
	IAggregate<IRobot*>* robots; //��������� �������
	static CentralController* self; //������������ ��������� �����������

	//��������� �����������, ����� ������������� �������� ���������� ����������� �����������
    CentralController(const std::string& name, IAggregate<IRobot*>* collection)
        : IController(name), robots(collection) {
    }

	//������� ���������� ����������� � �������� ������������
	//����� ������������� �������� ���������� ����������� �����������
    CentralController(const CentralController& root) = delete;
    CentralController& operator=(const CentralController&) = delete;
public:
	//����������� ����� ��� ��������� ������������� ���������� �����������
	static CentralController* getInstance(
		const std::string& name = "������� ����������",
		IAggregate<IRobot*>* collection = new MyList<IRobot*>()
	);

	//����� ��� ���������� ��������� �����������
	ControllerSnapshot* saveState() override;
	//����� ��� �������������� ��������� �����������
	void restoreState(ControllerSnapshot* m) override;

	//��������� ������ ��������� ������ ��
    void addRobot(IRobot* robot) override;
	void removeRobot(IRobot* robot) override;
    void dispatchDelivery(IRobot* robot, const std::string& destination) override;
    void monitorRobots() const override;

    const IAggregate<IRobot*>& getRobots() const override;
};