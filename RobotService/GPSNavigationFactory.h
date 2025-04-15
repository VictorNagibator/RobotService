#pragma once
#include "NavigationFactory.h"
#include "MapSegment.h"

class GPSNavigationFactory :
    public NavigationFactory
{
private:
    double standartAccuracy;
    int standartSateliteCount;
	MapSegment* currentMap; //Текущая карта
public:
	GPSNavigationFactory(MapSegment* map, double accuracy = 5.0, int sateliteCount = 4) 
		: currentMap(map), standartAccuracy(accuracy), standartSateliteCount(sateliteCount) {}
	INavigation* createNavigation(IEnvironment* environment, double startX = 0, double startY = 0) override;
};