#pragma once
#include "CommunicationFactory.h"
#include "CellularChannelPool.h"

class CellularCommunicationFactory :
    public CommunicationFactory
{
private:
	int standartLatency;
	CellularChannelPool* channelPool;
public:
	CellularCommunicationFactory(CellularChannelPool* pool, int latency = 50) 
		: channelPool(pool), standartLatency(latency) {}
	ICommunication* createCommunication(int signalStrength, IEnvironment* env) override;
};