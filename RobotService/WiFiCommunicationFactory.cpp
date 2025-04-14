#include "WiFiCommunicationFactory.h"
#include "WiFiCommunication.h"

ICommunication* WiFiCommunicationFactory::createCommunication(
	int signalStrength, IEnvironment* env)
{
	return new WiFiCommunication(signalStrength, standartChannel, env);
}