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
    void startDelivery(const std::string& destination, 
        const std::string& machineLocation = nullptr,
        int itemID = -1,
        IVendingMachine* vendingMachine = nullptr) override;
    void startCharging();
    void runDiagnostics();
    void wait();

    void checkStatus() override;
	void moveTo(const std::string& destination) override;
    IRobot* clone() const override;
};