#pragma once
#include "IEnvironment.h"

class GroundEnvironment : public IEnvironment {
public:
    double getResistance() const override;
    double getNavigationAccuracyFactor() const override;
    double getCommunicationAttenuation() const override;

    void interact();

    std::string getEnvironmentName() const override;
};