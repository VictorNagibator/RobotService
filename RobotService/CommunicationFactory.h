#pragma once
#include "ICommunication.h"
#include "IEnvironment.h"

class CommunicationFactory
{
public:
	virtual ICommunication* createCommunication(int signalStrength, IEnvironment* env) = 0;
};