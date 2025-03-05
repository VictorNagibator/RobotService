#pragma once
#include "IRobot.h"

//Летающий робот (дрон): используется для быстрой доставки, обхода заторов и доставки в труднодоступные районы
class Drone : public IRobot {
public:
    void startDelivery(const std::string& destination) override;
    void stopDelivery() override;
    void updateStatus() override;
};
