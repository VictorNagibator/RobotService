#include "GPSNavigation.h"
#include <iostream>

GPSNavigation::GPSNavigation(double accuracy, int satelliteCount, double startX, double startY)
    : INavigation(startX, startY)
{
    this->accuracy = accuracy;
    this->satelliteCount = satelliteCount;
}

void GPSNavigation::navigate(const std::string& destination)
{
    //Точность корректируется в зависимости от среды
    std::cout << "GPS-навигация: просчитываем маршрут до \"" << destination
		<< "\" с точностью " << accuracy - environment->getNavigationAccuracyFactor() 
        << " м., используя " << satelliteCount << " спутников.\n";
}

void GPSNavigation::updatePosition(double newX, double newY)
{
    updatePosition(newX, newY); //Обновляем координаты через стандартную реализацию
    std::cout << "GPS: обновалена позиция (" << x << ", " << y << ").\n";
}

void GPSNavigation::adjustRoute()
{
    std::cout << "GPS: пересчёт маршрута в среде: " 
        << environment->getEnvironmentName() << "...\n";
}