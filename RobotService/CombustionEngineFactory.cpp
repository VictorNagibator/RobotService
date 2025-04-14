#include "CombustionEngineFactory.h"
#include "CombustionEngine.h"

IEngine* CombustionEngineFactory::createEngine(const std::string& name,
	int maxRMP, int temperatureThreshold, IEnvironment* environment)
{
	return new CombustionEngine(name, maxRMP, temperatureThreshold, environment);
}
}