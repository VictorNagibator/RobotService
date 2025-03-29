#include "LidarNavigation.h"
#include <iostream>

LidarNavigation::LidarNavigation(int detectionRange, double laserFrequency, double startX, double startY)
    : INavigation(startX, startY)
{
    this->detectionRange = detectionRange;
    this->laserFrequency = laserFrequency;
}

void LidarNavigation::navigate(const std::string& destination) 
{
    std::cout << "Лидар: сканирую окружение в радиусе "
        << detectionRange << " м. с частотой лазера " << laserFrequency
        << " Гц для навигации до \"" << destination << "\"."
        << "Возможны неточности, коээфициент точности навигации: " << environment->getNavigationAccuracyFactor() << "\n";
}

void LidarNavigation::updatePosition(double newX, double newY)
{
    updatePosition(newX, newY);
    std::cout << "Лидар: обновлена позиция (" << x << ", " << y << ").\n";
}

void LidarNavigation::adjustRoute()
{
    std::cout << "Лидар: пытаюсь обнаружить и обойти препятствия в среде: " << environment->getEnvironmentName() << "...\n";
}