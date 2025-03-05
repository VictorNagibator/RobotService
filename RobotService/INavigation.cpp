#include "INavigation.h"

INavigation::INavigation(double startX = 0, double startY = 0)
{
	x = startX;
	y = startY;
}

void INavigation::updatePosition(double newX, double newY)
{
	x = newX;
	y = newY;
}