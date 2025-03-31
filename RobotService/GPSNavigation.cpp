#include "GPSNavigation.h"
#include "StringHelper.h"
#include <iostream>

GPSNavigation::GPSNavigation(IEnvironment* environment, double accuracy, int satelliteCount, double startX, double startY)
    : INavigation(environment, startX, startY)
{
    this->accuracy = accuracy;
    this->satelliteCount = satelliteCount;
}

void GPSNavigation::navigate(const std::string& destination)
{
	//������� �������� ������� ����� ��� ����� ����������
    std::istringstream iss(destination);
    std::string street;
    std::string houseStr;
	//�������� ����� � ����� ���� ����� ���������� ������ ����� �������
    if (std::getline(iss, street, ',') && std::getline(iss, houseStr)) {
        street = StringHelper::deleteSpaces(street); //�������� �������
        houseStr = StringHelper::deleteSpaces(street);
        int houseNumber = std::stoi(houseStr);

        //�������� ������� ����� ��� ������ �����
        MapSegment* segment = factory.getSegment(street, houseNumber);
        std::cout << "GPSNavigation: ������� ��������� ����� �������:\n";
        segment->printInfo();
        std::cout << "��� " << houseNumber << " ������ �� �������� "
            << "� ��������� " << accuracy - environment->getNavigationAccuracyFactor() 
            << " �., ��������� " << satelliteCount << " ���������.\n"; ;
    }
    else {
        std::cout << "GPSNavigation: �������� ������ ����� ����������.\n";
    }
}

void GPSNavigation::updatePosition(double newX, double newY)
{
    updatePosition(newX, newY); //��������� ���������� ����� ����������� ����������
    std::cout << "GPS: ���������� ������� (" << x << ", " << y << ").\n";
}

void GPSNavigation::adjustRoute()
{
    std::cout << "GPS: �������� �������� � �����: " 
        << environment->getEnvironmentName() << "...\n";
}