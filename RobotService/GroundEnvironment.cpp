#include "GroundEnvironment.h"
#include <iostream>

//Возьмем все коэффициенты за 1 в качестве стандарта

double GroundEnvironment::getResistance() const
{ 
	return 1.0; 
}

double GroundEnvironment::getNavigationAccuracyFactor() const
{ 
	return 1.0; 
}

double GroundEnvironment::getCommunicationAttenuation() const
{ 
	return 1.0;
}

std::string GroundEnvironment::getEnvironmentName() const
{ 
	return "Земля"; 
}

void GroundEnvironment::interact()
{
	std::cout << "Взаимодействую на поверхности..." << std::endl;
}