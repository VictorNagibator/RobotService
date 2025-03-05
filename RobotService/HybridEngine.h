#pragma once
#include "IEngine.h"

//Гибридный двигатель
class HybridEngine : public IEngine {
private:
    //Развивает что-то среднее между двигателем внутреннего сгорания и электромотором
    const int RPMonInitial = maxRPM * 0.7;
public:
    HybridEngine(const std::string& name, int maxRPM, int temperatureThreshold)
        : IEngine(name, maxRPM, temperatureThreshold) {}

    void start() override;
    void stop() override;
};