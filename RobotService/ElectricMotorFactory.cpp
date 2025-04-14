#include "ElectricMotorFactory.h"
#include "ElectricMotor.h"

IEngine* ElectricMotorFactory::createEngine(const std::string& name,
	int maxRMP, int temperatureThreshold, IEnvironment* environment)
{
	return new ElectricMotor(name, maxRMP, temperatureThreshold, environment);
}