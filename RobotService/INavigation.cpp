#include "INavigation.h"

INavigation::INavigation(IEnvironment* environment, double startX, double startY)
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

IEnvironment* INavigation::getEnvironment() const
{
	return environment;
}

double INavigation::getX() const
{
	return x;
}

double INavigation::getY() const
{
	return y;
}

void INavigation::accept(IComponentVisitor& v) const
{
	v.visit(*this);
}