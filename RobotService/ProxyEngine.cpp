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
        std::cout << "������� ����������� (" << currentTemperature
            << ") ��������� ������������ (" << temperatureThreshold
            << "). ��������� " << engineName << " �� ����� �����������.\n";

		throw std::exception("�������� ���������!");
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
        std::cout << "������� ����������� (" << currentTemperature
            << ") ��������� ������������ (" << temperatureThreshold
            << "). ������ ��������� ������� " << engineName << ".\n";
    }
    else {
        realEngine->setRPM(newRPM);
    }
}