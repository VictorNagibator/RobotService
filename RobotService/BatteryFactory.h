#pragma once
#include "PowerSourceFactory.h"

class BatteryFactory :
    public PowerSourceFactory
{
private:
	int standartCapacity;
public:
	BatteryFactory(int capacity = 5000) : standartCapacity(capacity) {}
	IPowerSource* createPowerSource(IEnvironment* env) override;
};