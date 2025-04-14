#pragma once

class IPrototypeNavigation
{
public:
	virtual IPrototypeNavigation* clone() const = 0;
};