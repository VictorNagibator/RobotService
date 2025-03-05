#include "ProxyEngine.h"
#include <iostream>

EngineProxy::EngineProxy(IEngine* engine) 
	: IEngine(engine->getName(), engine->getMaxRPM(), engine->getTemperatureThreshold())
{
	realEngine = engine;
}

void EngineProxy::start() 
{
    if (currentTemperature > temperatureThreshold) {
        std::cout << "Текущая температура (" << currentTemperature
            << ") превышает максимальную (" << temperatureThreshold
            << "). Двигатель " << engineName << " не может запуститься.\n";
    }
    else {
        realEngine->start();
    }
}

void EngineProxy::setRPM(int newRPM) 
{
    if (currentTemperature > temperatureThreshold) {
        std::cout << "Текущая температура (" << currentTemperature
            << ") превышает максимальную (" << temperatureThreshold
            << "). Нельзя увеличить обороты " << engineName << ".\n";
    }
    else {
        realEngine->setRPM(newRPM);
    }
}