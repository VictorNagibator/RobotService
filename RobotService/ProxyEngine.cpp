#include "ProxyEngine.h"
#include <iostream>

ProxyEngine::ProxyEngine(IEngine* engine) 
	: IEngine(engine->getName(), engine->getMaxRPM(), engine->getTemperatureThreshold(), engine->getEnvironment())
{
	realEngine = engine;
}

void ProxyEngine::start() 
{
    if (realEngine->getTemperature() > realEngine->getTemperatureThreshold()) {
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
    if (realEngine->getTemperature() > realEngine->getTemperatureThreshold()) {
        std::cout << "Текущая температура (" << currentTemperature
            << ") превышает максимальную (" << temperatureThreshold
            << "). Нельзя увеличить обороты " << engineName << ".\n";
    }
    else {
        realEngine->setRPM(newRPM);
    }
}

int ProxyEngine::getRPM() const
{
	return realEngine->getRPM();
}

void ProxyEngine::setTemperature(int newTemperature)
{
	realEngine->setTemperature(newTemperature);
}

int ProxyEngine::getTemperature() const
{
	return realEngine->getTemperature();
}

std::string ProxyEngine::getName() const
{
	return realEngine->getName();
}

int ProxyEngine::getMaxRPM() const
{
	return realEngine->getMaxRPM();
}

int ProxyEngine::getTemperatureThreshold() const
{
	return realEngine->getTemperatureThreshold();
}