#include "GPSNavigation.h"
#include <iostream>

GPSNavigation::GPSNavigation(double accuracy, int satelliteCount, double startX, double startY)
    : INavigation(startX, startY)
{
    this->accuracy = accuracy;
    this->satelliteCount = satelliteCount;
}

std::string GPSNavigation::trim(const std::string& s) {
    std::string result = s;
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
    result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), result.end());
    return result;
}

void GPSNavigation::navigate(const std::string& destination)
{
	//������� �������� ������� ����� ��� ����� ����������
    std::istringstream iss(destination);
    std::string street;
    std::string houseStr;
	//�������� ����� � ����� ���� ����� ���������� ������ ����� �������
    if (std::getline(iss, street, ',') && std::getline(iss, houseStr)) {
        street = trim(street);
        houseStr = trim(houseStr);
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