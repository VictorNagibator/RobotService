#pragma once
#include "NavigationFactory.h"

class LidarNavigationFactory :
    public NavigationFactory
{
private:
    double standartLaserFrequency;
    int standartDetectionRange;
public:
	LidarNavigationFactory(double laserFrequency = 60, int detectionRange = 5) :
		standartLaserFrequency(laserFrequency), standartDetectionRange(detectionRange) {
	}
	INavigation* createNavigation(IEnvironment* environment, double startX = 0, double startY = 0) override;
};