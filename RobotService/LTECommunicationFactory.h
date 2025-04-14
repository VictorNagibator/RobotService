#pragma once
#include "CommunicationFactory.h"

class LTECommunicationFactory :
    public CommunicationFactory
{
private:
	int standartLatency;
public:
	LTECommunicationFactory(int latency = 50) : standartLatency(latency) {}
	ICommunication* createCommunication(int signalStrength, IEnvironment* env) override;
};