#include "YandexNavigationAdapter.h"

//–еализуем все методы интерфейса INavigation, использу€ методы стороннего класса

void YandexNavigationAdapter::navigate(const std::string& destination) 
{
    originalNav.navigateOnRoute(destination);
}

void YandexNavigationAdapter::updatePosition(double newX, double newY)
{
    x = newX;
    y = newY;
    originalNav.updateCoords(newX, newY);
}

void YandexNavigationAdapter::adjustRoute() 
{
    originalNav.reAdjust();
}