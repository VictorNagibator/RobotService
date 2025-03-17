#pragma once
#include "IRobot.h"
#include "IAggregate.h"

//���������� �������� �������� - ������ �������
class RobotGroup : public IRobot
{
private:
    IAggregate<IRobot*>* robots;
public:
	RobotGroup(IAggregate<IRobot*>* collection) 
        : IRobot(0, "", nullptr, nullptr, nullptr, nullptr), robots(collection) {
    }

    void addRobot(IRobot* robot); //���������� ������ � ������
    void removeRobot(IRobot* robot); //� ��������

	//���������������� ������ IRobot
    void startDelivery(const std::string& destination) override;
    void stopDelivery() override;
    void checkStatus() override;
};