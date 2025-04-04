#pragma once
#include "IController.h"
#include "MyList.h"

//����������� ����������, �������������� ������� � ����������� �������
class CentralController : public IController {
private:
	IAggregate<IRobot*>* robots; //��������� �������
public:
    CentralController(const std::string& name, IAggregate<IRobot*>* collection) 
        : IController(name), robots(collection) {} 

    void addRobot(IRobot* robot) override;
	void removeRobot(IRobot* robot) override;
    void dispatchDelivery(IRobot* robot, const std::string& destination) override;
    void monitorRobots() const override;

    const IAggregate<IRobot*>& getRobots() const override;
};