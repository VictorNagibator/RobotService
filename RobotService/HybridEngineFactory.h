#pragma once
#include "EngineFactory.h"
class HybridEngineFactory :
    public EngineFactory
{
public:
    IEngine* createEngine(const std::string& name,
        int maxRMP, int temperatureThreshold, IEnvironment* environment) override;
};
