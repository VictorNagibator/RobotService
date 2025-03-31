#include "IEngine.h"

IEngine::IEngine(const std::string& name, int maxRPM, int temperatureThreshold, IEnvironment* environment)
{
    engineName = name;
    this->maxRPM = maxRPM;
    this->temperatureThreshold = temperatureThreshold;
	this->environment = environment;
}

void IEngine::setRPM(int newRPM) 
{ 
    //������ ����������� � ����������� �� ����, �������� ��� �������� �������
    if (newRPM > currentRPM) currentTemperature += temperatureDifference;
    else currentTemperature -= temperatureDifference;

    //������ ��������� ������� ���� �������������
    currentRPM = (newRPM <= maxRPM) ? newRPM : maxRPM;
}

int IEngine::getRPM() const
{ 
    return currentRPM; 
}

void IEngine::setTemperature(int newTemperature)
{
    this->currentTemperature = newTemperature;
}

int IEngine::getTemperature() const
{
    return currentTemperature;
}

std::string IEngine::getName() const
{
    return engineName;
}

int IEngine::getMaxRPM() const
{
    return maxRPM;
}

int IEngine::getTemperatureThreshold() const
{
    return temperatureThreshold;
}

void IEngine::setEnvironment(IEnvironment* env)
{
	environment = env;
}