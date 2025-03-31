#pragma once
#include "IEngine.h"

//Двигатель внутреннего сгорания
class CombustionEngine : public IEngine {
private:
    //Обычно двигатели внутреннего сгорания развивают такие обороты
    const int RPMonInitial = (maxRPM > 1000) ? 1000 : maxRPM;
public:
    CombustionEngine(const std::string& name, int maxRPM, int temperatureThreshold, IEnvironment* environment)
        : IEngine(name, maxRPM, temperatureThreshold, environment) {}

    void start() override;
    void stop() override;
};