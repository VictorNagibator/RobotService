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
    std::cout << "GPS-���������: ������������ ������� �� \"" << destination
        << "\" � ��������� " << accuracy
        << " �., ��������� " << satelliteCount << " ���������.\n";
}

void GPSNavigation::updatePosition(double newX, double newY)
{
    updatePosition(newX, newY); //��������� ���������� ����� ����������� ����������
    std::cout << "GPS: ���������� ������� (" << x << ", " << y << ").\n";
}

void GPSNavigation::adjustRoute()
{
    std::cout << "GPS: �������� ��������...\n";
}