#include "ICommunication.h"

ICommunication::ICommunication(int signalStrength, IEnvironment* env)
{
	this->signalStrength = signalStrength;
	environment = env;
}

int ICommunication::getSignalStrength() const
{
	return signalStrength;
}

void ICommunication::setEnvironment(IEnvironment* env)
{
	environment = env;
}

IEnvironment* ICommunication::getEnvironment() const
{
	return environment;
}

void ICommunication::accept(IComponentVisitor& v) const
{
	v.visit(*this);
}