#pragma once
#include "IRobot.h"

//Ќаземный робот: используетс€ дл€ доставки по городским улицам и тротуарам.
class GroundRobot : public IRobot {
public:
    void startDelivery(const std::string& destination) override;
    void stopDelivery() override;
    void updateStatus() override;
};