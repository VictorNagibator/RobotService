#include "GPSNavigationFactory.h"
#include "GPSNavigation.h"

INavigation* GPSNavigationFactory::createNavigation(IEnvironment* environment, double startX = 0, double startY = 0)
{
	return new GPSNavigation(environment, standartAccuracy, standartSateliteCount, startX, startY);
}