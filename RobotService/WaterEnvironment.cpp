#include "WaterEnvironment.h"
#include <iostream>

double WaterEnvironment::getResistance() const 
{ 
	return 1.5; //высокая сопротивляемость воды
} 

double WaterEnvironment::getNavigationAccuracyFactor() const
{
	return 1.2; //сложнее с навигацией (сигнал GPS может ухудшаться)
}

double WaterEnvironment::getCommunicationAttenuation() const
{
	return 1.5; //сильное затухание сигнала в воде
}

std::string WaterEnvironment::getEnvironmentName() const
{
	return "Вода";
}

void WaterEnvironment::interact()
{
	std::cout << "Взаимодействую в воде..." << std::endl;
}