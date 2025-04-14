#include "FuelCellFactory.h"

IPowerSource* FuelCellFactory::createPowerSource(IEnvironment* env)
{
	return new FuelCell(standartFuelType, standartCapacity, env);
}