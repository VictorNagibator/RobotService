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
        std::cout << "������� ����������� (" << currentTemperature
            << ") ��������� ������������ (" << temperatureThreshold
            << "). ��������� " << engineName << " �� ����� �����������.\n";
    }
    else {
        realEngine->start();
    }
}

void EngineProxy::setRPM(int newRPM) 
{
    if (currentTemperature > temperatureThreshold) {
        std::cout << "������� ����������� (" << currentTemperature
            << ") ��������� ������������ (" << temperatureThreshold
            << "). ������ ��������� ������� " << engineName << ".\n";
    }
    else {
        realEngine->setRPM(newRPM);
    }
}