#include "ProxyEngine.h"
#include <iostream>

ProxyEngine::ProxyEngine(IEngine* engine) 
	: IEngine(engine->getNameFromSnapshot(), engine->getMaxRPM(), engine->getTemperatureThreshold(), engine->getEnvironment())
{
	realEngine = engine;
}

void ProxyEngine::start() 
{
    if (realEngine->getTemperature() > realEngine->getTemperatureThreshold()) {
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
    if (realEngine->getTemperature() > realEngine->getTemperatureThreshold()) {
        std::cout << "������� ����������� (" << currentTemperature
            << ") ��������� ������������ (" << temperatureThreshold
            << "). ������ ��������� ������� " << engineName << ".\n";
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

std::string ProxyEngine::getNameFromSnapshot() const
{
	return realEngine->getNameFromSnapshot();
}

int ProxyEngine::getMaxRPM() const
{
	return realEngine->getMaxRPM();
}

int ProxyEngine::getTemperatureThreshold() const
{
	return realEngine->getTemperatureThreshold();
}