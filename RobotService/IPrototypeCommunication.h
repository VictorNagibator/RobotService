#pragma once

class IPrototypeCommunication
{
public:
	virtual IPrototypeCommunication* clone() const = 0;
};