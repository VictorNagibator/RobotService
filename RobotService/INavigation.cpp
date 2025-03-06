#include "INavigation.h"

INavigation::INavigation(double startX, double startY)
{
	x = startX;
	y = startY;
}

void INavigation::updatePosition(double newX, double newY)
{
	x = newX;
	y = newY;
}