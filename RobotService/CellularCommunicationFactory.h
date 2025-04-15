#pragma once
#include "CommunicationFactory.h"

class CellularCommunicationFactory :
    public CommunicationFactory
{
private:
	int standartLatency;
public:
	CellularCommunicationFactory(int latency = 50) : standartLatency(latency) {}
	ICommunication* createCommunication(int signalStrength, IEnvironment* env) override;
};