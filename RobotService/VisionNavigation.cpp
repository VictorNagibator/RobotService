#include "VisionNavigation.h"
#include <iostream>

VisionNavigation::VisionNavigation(const std::string& resolution, int frameRate, double startX, double startY)
    : INavigation(startX, startY)
{
    this->resolution = resolution;
    this->frameRate = frameRate;
}

void VisionNavigation::navigate(const std::string& destination) 
{
    std::cout << "Компьютерное зрение: разрешение камеры " << resolution
        << " и " << frameRate
        << " FPS, пытаюсь доехать до \"" << destination << "\".\n";
}

void VisionNavigation::updatePosition(double newX, double newY)
{
    updatePosition(newX, newY);
    std::cout << "Компьютерное зрение: обновляю позицию (" << x << ", " << y << ").\n";
}

void VisionNavigation::adjustRoute() 
{
    std::cout << "Компьютерное зрение: анализирую ситуацию через камеры...\n";
}