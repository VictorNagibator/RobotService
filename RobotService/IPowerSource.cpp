#include "IPowerSource.h"

void IPowerSource::setEnvironment(IEnvironment* env)
{
	environment = env;
}

IEnvironment* IPowerSource::getEnvironment() const
{
	return environment;
}