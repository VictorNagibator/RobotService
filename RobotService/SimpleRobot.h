#pragma once
#include "IRobot.h"

//Обычный робот
class SimpleRobot : public IRobot {
public:
    SimpleRobot(int id, const std::string& model, IEngine* eng,
        INavigation* nav, ICommunication* comm, IPowerSource* power) 
        : IRobot(id, model, eng, nav, comm, power) {}

    void startDelivery(const std::string& destination) override;
    void stopDelivery() override;
    void checkStatus() override;

	void moveTo(const std::string& destination) override;
};