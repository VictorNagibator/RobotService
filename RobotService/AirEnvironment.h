#pragma once
#include "IEnvironment.h"

//Реализация для воздушной среды
class AirEnvironment : public IEnvironment {
public:
    double getResistance() const override;
    double getNavigationAccuracyFactor() const override;
    double getCommunicationAttenuation() const override;
    std::string getEnvironmentName() const override;
};