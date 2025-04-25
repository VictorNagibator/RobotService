#pragma once
#include "IRobot.h"

//Обычный робот
class SimpleRobot : public IRobot {
public:
    SimpleRobot(int id, const std::string& model, IEngine* eng,
        INavigation* nav, ICommunication* comm, IPowerSource* power) 
        : IRobot(id, model, eng, nav, comm, power) {}

    void checkStatus() override;

	void moveTo(const std::string& destination) override;

    SimpleRobot* clone() const override;
};