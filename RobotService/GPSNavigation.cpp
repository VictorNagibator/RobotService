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
	//Сначала получаем сегмент карты для места назначения
    std::istringstream iss(destination);
    std::string street;
    std::string houseStr;
	//Получаем улицу и номер дома через разделение строки через запятую
    if (std::getline(iss, street, ',') && std::getline(iss, houseStr)) {
        street = trim(street);
        houseStr = trim(houseStr);
        int houseNumber = std::stoi(houseStr);

        //Получаем сегмент карты для данной улицы
        MapSegment* segment = factory.getSegment(street, houseNumber);
        std::cout << "GPSNavigation: Маршрут рассчитан через сегмент:\n";
        segment->printInfo();
        std::cout << "Дом " << houseNumber << " найден на сегменте "
            << "с точностью " << accuracy - environment->getNavigationAccuracyFactor() 
            << " м., используя " << satelliteCount << " спутников.\n"; ;
    }
    else {
        std::cout << "GPSNavigation: Неверный формат места назначения.\n";
    }
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