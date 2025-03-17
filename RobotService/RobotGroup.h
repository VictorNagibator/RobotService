#pragma once
#include "IRobot.h"
#include "IAggregate.h"

//Реализация паттерна композит - группа роботов
class RobotGroup : public IRobot
{
private:
    IAggregate<IRobot*>* robots;
public:
	RobotGroup(IAggregate<IRobot*>* collection) 
        : IRobot(0, "", nullptr, nullptr, nullptr, nullptr), robots(collection) {
    }

    void addRobot(IRobot* robot); //Добавление робота в группу
    void removeRobot(IRobot* robot); //И удаление

	//Переопределенные методы IRobot
    void startDelivery(const std::string& destination) override;
    void stopDelivery() override;
    void checkStatus() override;
};