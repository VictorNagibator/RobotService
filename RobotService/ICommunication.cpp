#include "ICommunication.h"

ICommunication::ICommunication(int signalStrength)
{
	this->signalStrength = signalStrength;
}

int ICommunication::getSignalStrength()
{
	return signalStrength;
}