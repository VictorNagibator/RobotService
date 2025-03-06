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
    std::cout << "GPS-навигаци€: просчитываем маршрут до \"" << destination
        << "\" с точностью " << accuracy
        << " м., использу€ " << satelliteCount << " спутников.\n";
}

void GPSNavigation::updatePosition(double newX, double newY)
{
    updatePosition(newX, newY); //ќбновл€ем координаты через стандартную реализацию
    std::cout << "GPS: обновалена позици€ (" << x << ", " << y << ").\n";
}

void GPSNavigation::adjustRoute()
{
    std::cout << "GPS: пересчЄт маршрута...\n";
}