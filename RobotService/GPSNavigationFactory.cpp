#include "GPSNavigationFactory.h"
#include "GPSNavigation.h"

INavigation* GPSNavigationFactory::createNavigation(IEnvironment* environment, double startX, double startY)
{
	return new GPSNavigation(environment, currentMap, standartAccuracy, standartSateliteCount, startX, startY);
}