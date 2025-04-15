#include "CellularCommunicationFactory.h"
#include "CellularCommunication.h"

ICommunication* CellularCommunicationFactory::createCommunication(
	int signalStrength, IEnvironment* env)
{
	return new CellularCommunication(signalStrength, standartLatency, env, channelPool);
}