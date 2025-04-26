#include "LidarNavigationFactory.h"
#include "LidarNavigation.h"

INavigation* LidarNavigationFactory::createNavigation(IEnvironment* environment, double startX, double startY)
{
	return new LidarNavigation(environment, standartDetectionRange, standartLaserFrequency, startX, startY);
}