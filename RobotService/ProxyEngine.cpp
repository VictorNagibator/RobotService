#include "ProxyEngine.h"
#include <iostream>

ProxyEngine::ProxyEngine(IEngine* engine) 
	: IEngine(engine->getName(), engine->getMaxRPM(), engine->getTemperatureThreshold())
{
	realEngine = engine;
}

void ProxyEngine::start() 
{
    if (currentTemperature > temperatureThreshold) {
        std::cout << "Текущая температура (" << currentTemperature
            << ") превышает максимальную (" << temperatureThreshold
            << "). Двигатель " << engineName << " не может запуститься.\n";

		throw std::exception("Перегрев двигателя!");
    }
    else {
        realEngine->start();
    }
}

void ProxyEngine::stop()
{
    realEngine->stop();
}

void ProxyEngine::setRPM(int newRPM) 
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