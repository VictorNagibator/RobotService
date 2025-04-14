#include "LTECommunicationFactory.h"
#include "LTECommunication.h"

ICommunication* LTECommunicationFactory::createCommunication(
	int signalStrength, IEnvironment* env)
{
	return new LTECommunication(signalStrength, standartLatency, env);
}