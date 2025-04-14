#include "GPSNavigationFactory.h"
#include "GPSNavigation.h"

INavigation* GPSNavigationFactory::createNavigation(IEnvironment* environment, double startX, double startY)
{
	return new GPSNavigation(environment, standartAccuracy, standartSateliteCount, startX, startY);
}