#pragma once
#include "IPowerSource.h"
#include "IEnvironment.h"

class PowerSourceFactory
{
public:
	virtual IPowerSource* createPowerSource(IEnvironment* env) = 0;
};