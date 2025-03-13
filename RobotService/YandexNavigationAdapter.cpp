#include "YandexNavigationAdapter.h"

//��������� ��� ������ ���������� INavigation, ��������� ������ ���������� ������

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