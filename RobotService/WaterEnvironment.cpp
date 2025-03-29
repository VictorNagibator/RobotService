#include "WaterEnvironment.h"

double WaterEnvironment::getResistance() const 
{ 
	return 1.5; //высока€ сопротивл€емость воды
} 

double WaterEnvironment::getNavigationAccuracyFactor() const
{
	return 1.2; //сложнее с навигацией (сигнал GPS может ухудшатьс€)
}

double WaterEnvironment::getCommunicationAttenuation() const
{
	return 1.5; //сильное затухание сигнала в воде
}

std::string WaterEnvironment::getEnvironmentName() const
{
	return "¬ода";
}