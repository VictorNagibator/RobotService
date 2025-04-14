#pragma once
#include "NavigationFactory.h"

class GPSNavigationFactory :
    public NavigationFactory
{
private:
    double standartAccuracy;
    int standartSateliteCount;
public:
	GPSNavigationFactory(double accuracy = 5.0, int sateliteCount = 4) 
		: standartAccuracy(accuracy), standartSateliteCount(sateliteCount) {}
	INavigation* createNavigation(IEnvironment* environment, double startX = 0, double startY = 0) override;
};