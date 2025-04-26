#include "YandexNavigationAdapter.h"

//–еализуем все методы интерфейса INavigation, использу€ методы стороннего класса

void YandexNavigationAdapter::navigate(const std::string& destination) 
{
    environment->interact();
    originalNav.navigateOnRoute(destination);
}

void YandexNavigationAdapter::updatePosition(double newX, double newY)
{
    environment->interact();
    x = newX;
    y = newY;
    originalNav.updateCoords(newX, newY);
}

void YandexNavigationAdapter::adjustRoute() 
{
    environment->interact();
    originalNav.reAdjust();
}

YandexNavigationAdapter* YandexNavigationAdapter::clone() const
{
	return new YandexNavigationAdapter(*this);
}

bool YandexNavigationAdapter::selfTest() const
{
	return true; //яндекс всегда работает :)
}