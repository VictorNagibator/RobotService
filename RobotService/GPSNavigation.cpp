#include "GPSNavigation.h"
#include "StringHelper.h"
#include <iostream>

GPSNavigation::GPSNavigation(IEnvironment* environment, MapSegment* map, 
    double accuracy, int satelliteCount, double startX, double startY)
    : INavigation(environment, startX, startY)
{
    this->accuracy = accuracy;
    this->satelliteCount = satelliteCount;
    currentMap = map;
}

void GPSNavigation::updateMap(MapSegment* newMap)
{
    currentMap = newMap;
    std::cout << "GPSNavigation: Карта обновлена.\n";
    std::cout << "GPSNavigation: Новая карта: ";
    currentMap->printMapInfo();
}

void GPSNavigation::navigate(const std::string& destination)
{
	//Сначала получаем сегмент карты для места назначения
    std::istringstream iss(destination);
    std::string street;
    std::string houseStr;
	//Получаем улицу и номер дома через разделение строки через запятую
    if (std::getline(iss, street, ',') && std::getline(iss, houseStr)) {
        street = StringHelper::deleteSpaces(street); //Обрезаем пробелы
        houseStr = StringHelper::deleteSpaces(houseStr);
        int houseNumber = std::stoi(houseStr);

        if (!currentMap->hasAddress(street, houseNumber))
        {
			//Если адрес не найден, то выходим
			std::cout << "GPSNavigation: Адрес не найден на карте.\n";
			return;
        }

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
    environment->interact();
    INavigation::updatePosition(newX, newY); //Обновляем координаты через стандартную реализацию
    std::cout << "GPS: обновлена позиция (" << x << ", " << y << ").\n";
}

void GPSNavigation::adjustRoute()
{
    environment->interact();
    std::cout << "GPS: пересчёт маршрута в среде: " 
        << environment->getEnvironmentName() << "...\n";
}

GPSNavigation* GPSNavigation::clone() const
{
	return new GPSNavigation(*this);
}