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
    //ћен€ем температуру в зависимости от того, повышаем или понижаем обороты
    if (newRPM > currentRPM) currentTemperature += temperatureDifference;
    else currentTemperature -= temperatureDifference;

    //Ќельз€ развивать обороты выше максимального
    currentRPM = (newRPM <= maxRPM) ? newRPM : maxRPM;
}

int IEngine::getRPM()
{ 
    return currentRPM; 
}

void IEngine::setTemperature(int newTemperature)
{
    this->currentTemperature = newTemperature;
}

int IEngine::getTemperature()
{
    return currentTemperature;
}

std::string IEngine::getName()
{
    return engineName;
}

int IEngine::getMaxRPM() 
{
    return maxRPM;
}

int IEngine::getTemperatureThreshold()
{
    return temperatureThreshold;
}

void IEngine::setEnvironment(IEnvironment* env)
{
	environment = env;
}