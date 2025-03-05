#include "VisionNavigation.h"
#include <iostream>

VisionNavigation::VisionNavigation(const std::string& resolution, int frameRate, double startX = 0, double startY = 0)
    : INavigation(startX, startY)
{
    this->resolution = resolution;
    this->frameRate = frameRate;
}

void VisionNavigation::navigate(const std::string& destination) 
{
    std::cout << "������������ ������: ���������� ������ " << resolution
        << " � " << frameRate
        << " FPS, ������� ������� �� \"" << destination << "\".\n";
}

void VisionNavigation::updatePosition(double newX, double newY)
{
    updatePosition(newX, newY);
    std::cout << "������������ ������: �������� ������� (" << x << ", " << y << ").\n";
}

void VisionNavigation::adjustRoute() 
{
    std::cout << "������������ ������: ���������� �������� ����� ������...\n";
}