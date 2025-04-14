#include "LidarNavigationFactory.h"
#include "LidarNavigation.h"

INavigation* LidarNavigationFactory::createNavigation(IEnvironment* environment, double startX, double startY)
{
	return new LidarNavigation(environment, standartLaserFrequency, standartDetectionRange, startX, startY);
}