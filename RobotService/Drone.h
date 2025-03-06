#pragma once
#include "IRobot.h"

//Летающий робот (дрон): используется для быстрой доставки, обхода заторов и доставки в труднодоступные районы
class Drone : public IRobot {
public:
    Drone(int id, const std::string& model, IEngine* eng,
        INavigation* nav, ICommunication* comm, IPowerSource* power)
        : IRobot(id, model, eng, nav, comm, power) {}

    void startDelivery(const std::string& destination) override;
    void stopDelivery() override;
    void checkStatus() override;
};
