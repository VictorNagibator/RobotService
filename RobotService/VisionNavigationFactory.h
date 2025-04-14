#pragma once
#include "NavigationFactory.h"

class VisionNavigationFactory :
    public NavigationFactory
{
private:
    std::string standartResolution;
    int standartFrameRate;
public:
	VisionNavigationFactory(std::string resolution, int frameRate) :
		standartResolution(resolution), standartFrameRate(frameRate) {}
	INavigation* createNavigation(IEnvironment* environment, double startX = 0, double startY = 0) override;
};