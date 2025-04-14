#pragma once
#include "INavigation.h"
#include "IEnvironment.h"

class NavigationFactory
{
public:
	virtual INavigation* createNavigation(IEnvironment* environment, double startX = 0, double startY = 0) = 0;
};