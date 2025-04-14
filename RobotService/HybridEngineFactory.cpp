#include "HybridEngineFactory.h"
#include "HybridEngine.h"

IEngine* HybridEngineFactory::createEngine(const std::string& name,
	int maxRMP, int temperatureThreshold, IEnvironment* environment)
{
	return new HybridEngine(name, maxRMP, temperatureThreshold, environment);
}