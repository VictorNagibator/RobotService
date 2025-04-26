#include "VisionNavigation.h"
#include <iostream>

VisionNavigation::VisionNavigation(IEnvironment* environment, 
    const std::string& resolution, int frameRate, double startX, double startY)
    : INavigation(environment, startX, startY)
{
    this->resolution = resolution;
    this->frameRate = frameRate;
}

void VisionNavigation::navigate(const std::string& destination) 
{
    environment->interact();
    std::cout << "Компьютерное зрение: разрешение камеры " << resolution
        << " и " << frameRate
        << " FPS, пытаюсь доехать до \"" << destination << "\"."
        << "Возможны неточности, коээфициент точности навигации: " << environment->getNavigationAccuracyFactor() << "\n";
}

void VisionNavigation::updatePosition(double newX, double newY)
{
    environment->interact();
    INavigation::updatePosition(newX, newY);
    std::cout << "Компьютерное зрение: обновляю позицию (" << x << ", " << y << ").\n";
}

void VisionNavigation::adjustRoute() 
{
    environment->interact();
    std::cout << "Компьютерное зрение: анализирую ситуацию через камеры в среде: " 
        << environment->getEnvironmentName() << "...\n";
}

VisionNavigation* VisionNavigation::clone() const
{
	return new VisionNavigation(*this);
}

bool VisionNavigation::selfTest() const
{
	if (frameRate <= 0) return false;
	return true;
}