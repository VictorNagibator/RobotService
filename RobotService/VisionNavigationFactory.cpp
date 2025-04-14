#include "VisionNavigationFactory.h"
#include "VisionNavigation.h"

INavigation* VisionNavigationFactory::createNavigation(IEnvironment* environment, double startX, double startY)
{
	return new VisionNavigation(environment, standartResolution, standartFrameRate, startX, startY);
}