#include "IEngine.h"

IEngine::IEngine(const std::string& name, int maxRPM, int temperatureThreshold)
{
    engineName = name;
    this->maxRPM = maxRPM;
    this->temperatureThreshold = temperatureThreshold;
}

void IEngine::setRPM(int newRPM)
{ 
    //������ ����������� � ����������� �� ����, �������� ��� �������� �������
    if (newRPM > currentRPM) currentTemperature += temperatureDifference;
    else currentTemperature -= temperatureDifference;

    //������ ��������� ������� ���� �������������
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