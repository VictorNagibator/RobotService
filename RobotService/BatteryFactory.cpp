#include "BatteryFactory.h"
#include "Battery.h"

IPowerSource* BatteryFactory::createPowerSource(IEnvironment* env)
{
	return new Battery(standartCapacity, env);
}