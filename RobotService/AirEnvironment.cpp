#include "AirEnvironment.h"
#include <iostream>

double AirEnvironment::getResistance() const 
{ 
	return 0.8; //меньше сопротивление (воздушное сопротивление менее ощутимо)
} 

double AirEnvironment::getNavigationAccuracyFactor() const 
{ 
	return 0.9; //немного точнее, меньше помех от преп€тствий
} 

double AirEnvironment::getCommunicationAttenuation() const 
{ 
	return 1.2; //больше затухани€ из-за атмосферных условий
} 

std::string AirEnvironment::getEnvironmentName() const 
{ 
	return "¬оздух"; 
}

void AirEnvironment::interact()
{
	std::cout << "¬заимодействую с воздухом..." << std::endl;
}