#include "LidarNavigation.h"
#include <iostream>

LidarNavigation::LidarNavigation(IEnvironment* environment, int detectionRange, 
    double laserFrequency, double startX, double startY)
    : INavigation(environment, startX, startY)
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
    environment->interact();
    updatePosition(newX, newY);
    std::cout << "Лидар: обновлена позиция (" << x << ", " << y << ").\n";
}

void LidarNavigation::adjustRoute()
{
    environment->interact();
    std::cout << "Лидар: пытаюсь обнаружить и обойти препятствия в среде: " << environment->getEnvironmentName() << "...\n";
}