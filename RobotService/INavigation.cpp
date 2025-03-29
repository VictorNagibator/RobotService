#include "INavigation.h"

INavigation::INavigation(double startX, double startY, IEnvironment* environment)
{
	x = startX;
	y = startY;
	this->environment = environment;
}

void INavigation::updatePosition(double newX, double newY)
{
	x = newX;
	y = newY;
}

void INavigation::setEnvironment(IEnvironment* env)
{
	environment = env;
}