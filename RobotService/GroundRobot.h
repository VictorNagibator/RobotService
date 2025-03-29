#pragma once
#include "IRobot.h"

//Ќаземный робот: используетс€ дл€ доставки по городским улицам и тротуарам.
class GroundRobot : public IRobot {
public:
    GroundRobot(int id, const std::string& model, IEngine* eng,
        INavigation* nav, ICommunication* comm, IPowerSource* power) 
        : IRobot(id, model, eng, nav, comm, power) {}

    void startDelivery(const std::string& destination) override;
    void stopDelivery() override;
    void checkStatus() override;

	void moveTo(const std::string& destination) override;
};