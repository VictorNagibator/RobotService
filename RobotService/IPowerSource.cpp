#include "IPowerSource.h"

void IPowerSource::setEnvironment(IEnvironment* env)
{
	environment = env;
}

IEnvironment* IPowerSource::getEnvironment() const
{
	return environment;
}

void IPowerSource::accept(IComponentVisitor& v) const
{
	v.visit(*this);
}