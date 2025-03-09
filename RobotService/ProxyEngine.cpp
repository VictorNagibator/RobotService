#include "ProxyEngine.h"
#include <iostream>

ProxyEngine::ProxyEngine(IEngine* engine) 
	: IEngine(engine->getName(), engine->getMaxRPM(), engine->getTemperatureThreshold())
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

int ProxyEngine::getRPM()
{
	return realEngine->getRPM();
}

void ProxyEngine::setTemperature(int newTemperature)
{
	realEngine->setTemperature(newTemperature);
}

int ProxyEngine::getTemperature()
{
	return realEngine->getTemperature();
}

std::string ProxyEngine::getName()
{
	return realEngine->getName();
}

int ProxyEngine::getMaxRPM()
{
	return realEngine->getMaxRPM();
}

int ProxyEngine::getTemperatureThreshold()
{
	return realEngine->getTemperatureThreshold();
}