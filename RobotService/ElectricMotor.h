#pragma once
#include "IEngine.h"

//Ёлектродвигатель
class ElectricMotor : public IEngine {
private:
    const int RPMonInitial = maxRPM * 0.9; //ќбороты электромотора при старте - практически сразу очень высокие
public:
    ElectricMotor(const std::string& name, int maxRPM, int temperatureThreshold, IEnvironment* environment)
        : IEngine(name, maxRPM, temperatureThreshold, environment) {}

    void start() override;
    void stop() override;

    ElectricMotor* clone() const override;
};