#pragma once
#include "PowerSourceFactory.h"
#include "FuelCell.h"

class FuelCellFactory :
    public PowerSourceFactory
{
private:
	int standartCapacity;
	FuelType standartFuelType;
public:
	FuelCellFactory(int capacity = 5000, FuelType type = A92) 
		: standartCapacity(capacity), standartFuelType(type) {}
	IPowerSource* createPowerSource(IEnvironment* env) override;
};