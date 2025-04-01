#pragma once
#include "IEnvironment.h"

//Реализация для водной среды
class WaterEnvironment : public IEnvironment {
public:
    double getResistance() const override;
    double getNavigationAccuracyFactor() const override;
    double getCommunicationAttenuation() const override;

    void interact();

    std::string getEnvironmentName() const override;
};